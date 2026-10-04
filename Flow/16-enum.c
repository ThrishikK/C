#include <stdio.h>

enum State
{
    OFF,
    ON,
    ERROR
};

int main()
{
    enum State deviceState = ERROR;

    if (deviceState == OFF)
    {
        printf("Device is OFF\n");
    }
    else if (deviceState == ON)
    {
        printf("Device is ON\n");
    }
    else if (deviceState == ERROR)
    {
        printf("Device has an ERROR\n");
    }

    return 0;
}