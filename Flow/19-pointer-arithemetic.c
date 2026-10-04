#include <stdio.h>

int main()
{
    int numbers[3] = {10, 20, 30};

    int *ptr = numbers;

    printf("First: %d\n", *ptr);

    ptr++;

    printf("Second: %d\n", *ptr);

    ptr++;

    printf("Third: %d\n", *ptr);

    return 0;
}