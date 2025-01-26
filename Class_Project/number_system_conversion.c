#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
void inputMenuOptions()
{
    printf("Please Select any of the below for Input type.......\n");
    printf("PRESS....\n");
    printf("1 for Binary.\n");
    printf("2 for Octal.\n");
    printf("3 for Decimal.\n");
    printf("4 for Hexadecimal.\n\n\n");
}
void outputMenuOptions()
{
    printf("\nIn which type of Number you want to convert in.....\n");
    printf("PRESS....\n");
    printf("1 for Binary\n");
    printf("2 for Octal.\n");
    printf("3 for Decimal.\n");
    printf("3 for HexaDecimal.\n\n\n");
}
// string reverse
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
// Verifying Inputs
int isBinaryNumber(int num)
{
    int isBin = 0; // initialy False
    while (num != 0)
    {
        if (num % 10 == 0 || num % 10 == 1)
        {
            num = num / 10;
            isBin = 1;
        }
        else
        {
            break;
        }
    }
    return isBin;
}
// Binary Input
int userInput()
{
    int num;
    printf("Enter the Binary Number ");
    scanf("%d", &num);
    return num;
}
// binaryToDecimal
int binaryToDecimal(int num)
{
    int power, sum, unitDigit;
    sum = 0;
    power = 0;
    while (num != 0)
    {
        unitDigit = num % 10;
        sum += (unitDigit * pow(2, power));
        power++;
        num = num / 10;
    }
    return sum;
}
// Decimal to Octal
int decimalToOctal(int num)
{
    int rem, sum, multiply, actualDecimal;
    actualDecimal = num;
    sum = 0;
    multiply = 1;
    while (num != 0)
    {
        rem = num % 8;
        sum += (multiply * rem);
        multiply *= 10;
        num /= 8;
    }
    return sum;
}
// Decimal to HexaDecimal
char *decimalToHexaDecimal(int num)
{
    int rem;
    char ch[2];
    char str[20] = "";
    char *hD;
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
    return stringReverse(str);
}
int main()
{
    int inputChoice, outputChoice, number;
    printf("\n\nHello User....!\nI'm here to assist you in converting various types of numbers into any specific format of your choice.\n");
    printf("\n********************************************************************************\n\n");
    inputMenuOptions();
    printf("Enter Your Choice : ");
    scanf("%d", &inputChoice);
    switch (inputChoice)
    {
    case 1:
        number = userInput();
        if (isBinaryNumber(number))
        {
            outputMenuOptions();
            printf("Enter Your Choice : ");
            scanf("%d", &outputChoice);
            switch (outputChoice)
            {
            case 1:
                printf("\n\nThe Binary value of %d is %d\n", number, number);
                break;
            case 2:
                printf("\n\nThe Octal value of %d is %d\n", number, decimalToOctal(binaryToDecimal(number)));
                break;
            case 3:
                printf("\n\nThe Decimal value of %d is %d\n", number, binaryToDecimal(number));
                break;
            case 4:
                printf("\n\nThe HexaDecimal value of %d is %s\n", number, decimalToHexaDecimal(binaryToDecimal(number)));
                break;
            default:
                printf("Shi se chhose kro yaar...!");
                break;
            }
        }
        else
        {
            printf("Entered Number is not Binary.");
            exit(1);
        }
        break;
    // case 2:
    //     octalInput();
    //     outputMenuOptions();
    //     break;
    // case 3:
    //     decimalInput();
    //     outputMenuOptions();
    //     break;
    // case 4:
    //     hexaDecimalInput();
    //     outputMenuOptions();
    //     break;
    default:
        printf("Andha h Kya...\n");
        break;
    }
    return 0;
}