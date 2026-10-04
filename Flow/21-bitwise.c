#include <stdio.h>

int main()
{
    unsigned int a = 10;
    unsigned int b = 12;

    printf("AND = %u\n", a & b);
    printf("OR  = %u\n", a | b);
    printf("XOR = %u\n", a ^ b);
    printf("NOT = %u\n", ~a);

    return 0;
}