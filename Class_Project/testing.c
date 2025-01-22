#include <stdio.h>
#include <string.h>

int main()
{
    // char ch[10] = ""; // Initialize with an empty string
    // int a = 6;

    // ch[0] = '0' + a; // Convert the integer to a character
    // ch[1] = '\0';    // Null-terminate the string

    // strcat(ch, "A"); // Concatenate "A" to ch

    // printf("Hello\n");
    // printf("%s", ch); // Print the resulting string
    // strcat(ch, "B");
    // printf("\n%s", ch); // Print the resulting string

    char ch[2];
    strcpy(ch, "A");
    printf("%s\n", ch);
    strcpy(ch, "B");
    printf("%s\n", ch);
    return 0;
}
