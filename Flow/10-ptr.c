#include <stdio.h>

int main()
{
    int age = 27;

    int *ptr = &age;

    printf("Age: %d\n", age);
    printf("Address: %p\n", (void *)&age);
    printf("Value through pointer: %d\n", *ptr);

    return 0;
}