#include <stdio.h>

#define POWER_BIT 0
#define READY_BIT 1
#define ERROR_BIT 2
#define INTERRUPT_BIT 3

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
    unsigned int status;
} Device;

const float MAX_VOLTAGE = 5.0;

volatile unsigned int hardware_event = 0;

void turn_on(Device *device)
{
    device->state = ON;
    device->status |= (1 << POWER_BIT);
}

void set_ready(Device *device)
{
    device->status |= (1 << READY_BIT);
}

void set_error(Device *device)
{
    device->state = ERROR;
    device->status |= (1 << ERROR_BIT);
}

void turn_off(Device *device)
{
    device->state = OFF;
    device->status &= ~(1 << POWER_BIT);
}

int is_ready(Device *device)
{
    return (device->status & (1 << READY_BIT)) != 0;
}

void record_operation()
{
    static int count = 0;

    count++;

    printf("Operations: %d\n", count);
}

void print_device(Device *device)
{
    printf("\n--- Device ---\n");

    printf("ID: %d\n", device->id);
    printf("Voltage: %.2f V\n", device->voltage);

    if (device->state == OFF)
        printf("State: OFF\n");
    else if (device->state == ON)
        printf("State: ON\n");
    else
        printf("State: ERROR\n");

    printf("Status: %u\n", device->status);
}

int main()
{
    Device device = {101, 3.3, OFF, 0};

    printf("Maximum voltage: %.1f V\n", MAX_VOLTAGE);

    print_device(&device);

    printf("\nTurning device ON...\n");
    turn_on(&device);
    record_operation();

    printf("\nSetting device READY...\n");
    set_ready(&device);
    record_operation();

    if (is_ready(&device))
    {
        printf("Device is READY\n");
    }

    printf("\nSimulating ERROR...\n");
    set_error(&device);
    record_operation();

    print_device(&device);

    printf("\nTurning device OFF...\n");
    turn_off(&device);
    record_operation();

    print_device(&device);

    return 0;
}