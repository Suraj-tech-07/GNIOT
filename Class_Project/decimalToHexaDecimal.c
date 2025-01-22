#include <stdio.h>

int main()
{
    int num = 7432;
    char str[20]; // Allocate enough space for the string

    sprintf(str, "%x", num);
    printf("String: %s\n", str);

    return 0;
}

// %d is used for integers.
// %f is used for floating-point numbers.
// %x is used for hexadecimal numbers.