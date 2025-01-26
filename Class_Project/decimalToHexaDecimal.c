#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char *stringReverse(char *st)
{
    int length = strlen(st);
    char *result = (char *)malloc(length);
    for (int i = 0; i < length; i++)
    {
        result[i] = st[length - i - 1];
    }
    st[length] = '\0';
    return result;
}

int main()
{
    int num = 678;
    int rem;
    char ch[2];
    char str[20] = "";
    while (num != 0)
    {
        rem = num % 16;
        switch (rem)
        {
        case 10:
            strcpy(ch, "A");
            break;
        case 11:
            strcpy(ch, "B");
            break;
        case 12:
            strcpy(ch, "C");
            break;
        case 13:
            strcpy(ch, "D");
            break;
        case 14:
            strcpy(ch, "E");
            break;
        case 15:
            strcpy(ch, "F");
            break;
        default:
            ch[0] = '0' + rem;
            ch[1] = '\0';
            break;
        }
        strcat(str, ch);
        num /= 16;
    }
    printf("%s", stringReverse(str)); 
}

// int main()
//     {
//         int num = 7432;
//         char str[20]; // Allocate enough space for the string

//         sprintf(str, "%x", num);
//         printf("String: %s\n", str);
//         return 0;
//     }

// %d is used for integers.
// %f is used for floating-point numbers.
// %x is used for hexadecimal numbers.