#include <stdio.h>

void counter()
{
    static int count = 0;

    count++;

    printf("Count = %d\n", count);
}

int main()
{
    volatile int flag = 1;

    const int MAX = 100;

    counter();
    counter();
    counter();

    printf("Flag = %d\n", flag);
    printf("MAX = %d\n", MAX);

    return 0;
}