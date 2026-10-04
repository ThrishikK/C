#include <stdio.h>

// EMPTY LINE
void emptyLine()
{
    printf("\n");
}

// COMMENT
void comment(char sentence[])
{
    printf("++++++++++++++++++++++++++++++++++\n");
    printf("%s\n", sentence);
    printf("++++++++++++++++++++++++++++++++++\n");
}

void charArray()
{
    char demo[] = "EPSILON";
    printf("Given string : %s\n", demo);

    printf("Reading character by character \n");

    for (int i = 0; demo[i] != '\0'; i++)
    {
        printf("Current character =>  %c\n", demo[i]);
    }
    emptyLine();
}

// POINTER RELATED

void pointerRelated()
{

    int age = 27;
    int *ptr = &age;
    printf("Variable value is %d\n", age);
    printf("Address accessing using & operator ->  %p\n", &age);
    printf("Address accessing using pointer -> %p\n", (void *)ptr);

    // ARRAY
    int a[5] = {123, 246, 369, 492, 615};
    int *a_ptr = a;
    // *a_ptr = 248;
    printf("Accessing first element in array using pointers => %d\n", *a_ptr);
    printf("Accessing 2nd element in array using pointers => %d\n", *(a_ptr + 1));

    emptyLine();
}

int main()
{
    // FUNCTION CALLS
    comment("Character Array");
    charArray();
    comment("Pointer Related");
    pointerRelated();
    return 0;
}