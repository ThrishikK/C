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

void pointerExercise()
{
    int x = 540;
    int *ptr = &x;

    printf("%d\n", x);
    printf("%d\n", *ptr);
    printf("%p\n", ptr);
    printf("%p\n", &x);
    emptyLine();
};

// STRUCTS

void showStruct()
{
    struct Adapter
    {
        int input_voltage;
        int input_frequency;
        float output_voltage;
        float output_current;
    };

    struct Adapter laptop_adapter = {240, 50, 19.5, 3.33};

    printf("Laptop adapter specifications input voltage => %d V\n", laptop_adapter.input_voltage);
    printf("Laptop adapter specifications input frequency => %d Hz\n", laptop_adapter.input_frequency);
    printf("Laptop adapter specifications output voltage => %.1f V\n", laptop_adapter.output_voltage);
    printf("Laptop adapter specifications output current => %.2f A\n", laptop_adapter.output_current);
    emptyLine();
};

// ENUM

void showEnum()
{

    enum State
    {
        OFF,
        ON,
        ERROR
    };

    enum State laptop_state = ERROR;

    if (laptop_state == OFF)
    {
        printf("Current laptop status is OFF corresponding value => %d\n", laptop_state);
    }
    else if (laptop_state == ON)
    {
        printf("Current laptop status is ON corresponding value => %d\n", laptop_state);
    }
    else if (laptop_state == ERROR)
    {
        printf("Current laptop status is ERROR corresponding value => %d\n", laptop_state);
    }
    emptyLine();
};

// TYPEDEF

void showTypedef()
{
    typedef enum
    {
        OFF,
        ON,
        ERROR
    } State;

    typedef struct
    {
        int input_voltage;
        int input_frequency;
        float output_voltage;
        float output_current;
        State state;
    } Adapter;

    Adapter laptop_adapter = {240, 50, 19.5, 3.33, OFF};

    printf("Laptop adapter specifications input voltage => %d V\n", laptop_adapter.input_voltage);
    printf("Laptop adapter specifications input frequency => %d Hz\n", laptop_adapter.input_frequency);
    printf("Laptop adapter specifications output voltage => %.1f V\n", laptop_adapter.output_voltage);
    printf("Laptop adapter specifications output current => %.2f A\n", laptop_adapter.output_current);

    if (laptop_adapter.state == OFF)
    {
        printf("Current laptop status is OFF corresponding value => %d\n", laptop_adapter.state);
    }
    else if (laptop_adapter.state == ON)
    {
        printf("Current laptop status is ON corresponding value => %d\n", laptop_adapter.state);
    }
    else if (laptop_adapter.state == ERROR)
    {
        printf("Current laptop status is ERROR corresponding value => %d\n", laptop_adapter.state);
    }
    emptyLine();
}

// MAIN
int main()
{
    // FUNCTION CALLS
    comment("Character Array");
    charArray();

    // POINTER RELATED
    comment("Pointer Related");
    pointerRelated();

    // POINTER EXERCISE
    comment("Pointer Exercise");
    pointerExercise();

    // STRUCTS
    comment("STRUCTS RELATED");
    showStruct();

    // STRUCTS
    comment("ENUM RELATED");
    showEnum();

    // TYPEDEF
    comment("TYPEDEF RELATED");
    showTypedef();

    return 0;
}