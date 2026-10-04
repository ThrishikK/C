#include <stdio.h>

int main()
{
    unsigned int status = 0;

    // Set ENABLE
    status |= (1 << 0);

    // Set READY
    status |= (1 << 2);

    printf("Status = %u\n", status);

    // Check READY
    if (status & (1 << 2))
    {
        printf("Device is READY\n");
    }

    // Clear ENABLE
    status &= ~(1 << 0);

    // Toggle ERROR
    status ^= (1 << 1);

    printf("Final Status = %u\n", status);

    return 0;
}