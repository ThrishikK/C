#include <stdio.h>

int main()
{
    int x = 10;
    float y = 3.14;
    char z = 'A';

    printf("int: %zu bytes\n", sizeof(x));
    printf("float: %zu bytes\n", sizeof(y));
    printf("char: %zu byte\n", sizeof(z));

    return 0;
}