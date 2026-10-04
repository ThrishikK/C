/*
 * Dancing Links (DLX) Sudoku Solver
 * ---------------------------------
 * Donald Knuth's "Algorithm X" solves the EXACT COVER problem:
 *   given a 0/1 matrix, pick rows so that every column has exactly one 1.
 *
 * Sudoku maps onto exact cover neatly:
 *   Rows    = 729 candidates "put digit d in cell (r,c)"   (9 * 9 * 9)
 *   Columns = 324 constraints, each of which must be met exactly once:
 *               81  cell (r,c) has a digit
 *               81  row r contains digit d
 *               81  column c contains digit d
 *               81  box b contains digit d
 *   Every candidate row has exactly four 1s (one per constraint type).
 *
 * "Dancing Links" stores the sparse matrix as circular doubly-linked lists.
 * Removing a node is  L->R = R;  R->L = L;  and it can be undone perfectly by
 * reversing the order, because the removed node still remembers its neighbours.
 * That makes backtracking nearly free.
 *
 * Build:  gcc -O2 -o dlx_sudoku dlx_sudoku.c
 * Usage:  ./dlx_sudoku                       (solves a famously hard puzzle)
 *         ./dlx_sudoku "53..7....6..195...."  (81 chars, '.' or '0' = blank)
 */

#include <stdio.h>
#include <string.h>

#define NCOLS    324
#define NROWS    729
#define MAXNODES (1 + NCOLS + NROWS * 4)

typedef struct {
    int L, R, U, D;   /* circular links (indices into nodes[]) */
    int C;            /* column header this node belongs to     */
    int row;          /* candidate id = r*81 + c*9 + d          */
} Node;

static Node nodes[MAXNODES];   /* node 0 = root, 1..324 = column headers */
static int  size[NCOLS + 1];   /* number of 1s currently in each column   */
static int  nnodes;
static int  solution[81];      /* candidate ids chosen so far             */
static long guesses;           /* branching statistic                     */

/* ---------- matrix construction ---------- */

static void init_matrix(void)
{
    for (int i = 0; i <= NCOLS; i++) {
        nodes[i].L = (i + NCOLS) % (NCOLS + 1);
        nodes[i].R = (i + 1) % (NCOLS + 1);
        nodes[i].U = nodes[i].D = nodes[i].C = i;
        size[i] = 0;
    }
    nnodes = NCOLS + 1;
}

/* Append a matrix row with 1s in the four given columns. */
static void add_row(int id, const int cols[4])
{
    int first = -1;
    for (int k = 0; k < 4; k++) {
        int c = cols[k], n = nnodes++;
        nodes[n].C = c;
        nodes[n].row = id;

        /* vertical: insert at bottom of column c */
        nodes[n].U = nodes[c].U;
        nodes[n].D = c;
        nodes[nodes[c].U].D = n;
        nodes[c].U = n;
        size[c]++;

        /* horizontal: splice into this row's circular list */
        if (first < 0) {
            first = n;
            nodes[n].L = nodes[n].R = n;
        } else {
            nodes[n].L = nodes[first].L;
            nodes[n].R = first;
            nodes[nodes[first].L].R = n;
            nodes[first].L = n;
        }
    }
}

/* ---------- the "dance" ---------- */

/* Remove column c, and every row that has a 1 in c, from the matrix. */
static void cover(int c)
{
    nodes[nodes[c].R].L = nodes[c].L;
    nodes[nodes[c].L].R = nodes[c].R;
    for (int i = nodes[c].D; i != c; i = nodes[i].D)
        for (int j = nodes[i].R; j != i; j = nodes[j].R) {
            nodes[nodes[j].D].U = nodes[j].U;
            nodes[nodes[j].U].D = nodes[j].D;
            size[nodes[j].C]--;
        }
}

/* Exact reverse of cover(): relink everything in opposite order. */
static void uncover(int c)
{
    for (int i = nodes[c].U; i != c; i = nodes[i].U)
        for (int j = nodes[i].L; j != i; j = nodes[j].L) {
            size[nodes[j].C]++;
            nodes[nodes[j].D].U = j;
            nodes[nodes[j].U].D = j;
        }
    nodes[nodes[c].R].L = c;
    nodes[nodes[c].L].R = c;
}

/* Algorithm X: returns 1 if an exact cover was found. */
static int search(int k)
{
    if (nodes[0].R == 0) return 1;          /* no columns left: solved */

    /* Heuristic: branch on the most constrained column (fewest options). */
    int c = nodes[0].R;
    for (int j = nodes[c].R; j != 0; j = nodes[j].R)
        if (size[j] < size[c]) c = j;
    if (size[c] == 0) return 0;             /* dead end */

    cover(c);
    for (int r = nodes[c].D; r != c; r = nodes[r].D) {
        guesses++;
        solution[k] = nodes[r].row;
        for (int j = nodes[r].R; j != r; j = nodes[j].R) cover(nodes[j].C);

        if (search(k + 1)) return 1;

        for (int j = nodes[r].L; j != r; j = nodes[j].L) uncover(nodes[j].C);
    }
    uncover(c);
    return 0;
}

/* ---------- Sudoku glue ---------- */

static int solve(int grid[9][9])
{
    init_matrix();
    for (int r = 0; r < 9; r++)
        for (int c = 0; c < 9; c++)
            for (int d = 0; d < 9; d++) {
                /* Given cells only get their one fixed candidate. */
                if (grid[r][c] != 0 && grid[r][c] != d + 1) continue;
                int box = (r / 3) * 3 + c / 3;
                int cols[4] = {
                    1 +       r * 9 + c,     /* cell filled       */
                    1 +  81 + r * 9 + d,     /* row has digit     */
                    1 + 162 + c * 9 + d,     /* column has digit  */
                    1 + 243 + box * 9 + d    /* box has digit     */
                };
                add_row(r * 81 + c * 9 + d, cols);
            }

    guesses = 0;
    if (!search(0)) return 0;

    for (int i = 0; i < 81; i++) {
        int id = solution[i];
        grid[id / 81][(id / 9) % 9] = id % 9 + 1;
    }
    return 1;
}

static void print_grid(int g[9][9])
{
    for (int r = 0; r < 9; r++) {
        if (r % 3 == 0 && r) printf("------+-------+------\n");
        for (int c = 0; c < 9; c++) {
            if (c % 3 == 0 && c) printf("| ");
            if (g[r][c]) printf("%d ", g[r][c]); else printf(". ");
        }
        printf("\n");
    }
}

int main(int argc, char **argv)
{
    /* Arto Inkala's "world's hardest sudoku" (2012) */
    const char *puzzle =
        "8........"
        "..36....."
        ".7..9.2.."
        ".5...7..."
        "....457.."
        "...1...3."
        "..1....68"
        "..85...1."
        ".9....4..";
    if (argc > 1) puzzle = argv[1];

    if (strlen(puzzle) != 81) {
        fprintf(stderr, "Puzzle must be exactly 81 characters.\n");
        return 1;
    }

    int grid[9][9];
    for (int i = 0; i < 81; i++) {
        char ch = puzzle[i];
        grid[i / 9][i % 9] = (ch >= '1' && ch <= '9') ? ch - '0' : 0;
    }

    printf("Puzzle:\n");
    print_grid(grid);

    if (solve(grid)) {
        printf("\nSolved (%ld candidate placements tried):\n", guesses);
        print_grid(grid);
    } else {
        printf("\nNo solution exists.\n");
        return 2;
    }
    return 0;
}
