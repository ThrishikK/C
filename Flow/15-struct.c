#include <stdio.h>

struct Device
{
    int id;
    float voltage;
};

int main()
{
    struct Device d1 = {101, 3.3};

    printf("Device ID: %d\n", d1.id);
    printf("Voltage: %.1f V\n", d1.voltage);

    return 0;
}