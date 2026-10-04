#include <stdio.h>

int main()
{
    int number = 100;

    int *ptr = &number;

    printf("Before: %d\n", number);

    *ptr = 200;

    printf("After: %d\n", number);

    return 0;
}