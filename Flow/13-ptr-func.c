#include <stdio.h>

void change(int *ptr)
{
    *ptr = 100;
}

int main()
{
    int number = 10;

    printf("Before: %d\n", number);

    change(&number);

    printf("After: %d\n", number);

    return 0;
}