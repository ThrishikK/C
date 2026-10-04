#include <stdio.h>

void normal_counter()
{
    int count = 0;

    count++;
    printf("Normal: %d\n", count);
}

void static_counter()
{
    static int count = 0;

    count++;
    printf("Static: %d\n", count);
}

int main()
{
    normal_counter();
    normal_counter();
    normal_counter();

    printf("\n");

    static_counter();
    static_counter();
    static_counter();

    return 0;
}