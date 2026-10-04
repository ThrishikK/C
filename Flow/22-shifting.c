#include <stdio.h>

int main()
{
    unsigned int x = 5;

    printf("x      = %u\n", x);
    printf("x << 1 = %u\n", x << 1);
    printf("x << 2 = %u\n", x << 2);
    printf("x << 3 = %u\n", x << 3);

    printf("x >> 1 = %u\n", x >> 1);
    printf("x >> 2 = %u\n", x >> 2);

    return 0;
}