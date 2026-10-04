#include <stdio.h>

typedef enum
{
    OFF,
    ON,
    ERROR
} State;

typedef struct
{
    int id;
    float voltage;
    State state;
} Device;

int main()
{
    Device d1 = {101, 3.3, ON};

    printf("Device ID: %d\n", d1.id);
    printf("Voltage: %.1f V\n", d1.voltage);

    if (d1.state == ON)
    {
        printf("State: ON\n");
    }

    return 0;
}