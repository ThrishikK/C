#include <stdio.h>

int main()
{
    int numbers[3] = {10, 20, 30};

    int *ptr = numbers;

    printf("First: %d\n", *ptr);
    printf("Second: %d\n", *(ptr + 1));
    printf("Third: %d\n", *(ptr + 2));

    *(ptr + 1) = 99;

    printf("After change: %d\n", numbers[1]);

    return 0;
}