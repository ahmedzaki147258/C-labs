#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x = 5, y=2;
    float div = x/y;

    printf("%f \n", div);
    // Write a C program to test different format with specifiers printf
    int intNum = 4;
    printf("Integer format -->\n");
    printf("Decimal: %d\n\n", intNum);

    float floatNum = 3.14;
    printf("Floating formats -->\n");
    printf("Float: %f\n", floatNum);
    printf("Float with fixed-point: %0.2f\n\n", floatNum);

    char ch = 'A';
    printf("Character format: -->\n");
    printf("Character: %c\n\n", ch);

    // Write a C program to read a character from the user and print it and its ASCII code.
    char inputChar;
    printf("Enter a character: ");
    scanf("%c", &inputChar);
    printf("character is: %c\n", inputChar);
    printf("ASCII code: %d\n\n", inputChar);

    // Write a C program to display the octal and the hexadecimal representation of an integer number
    int inputNum;
    printf("Enter an integer: ");
    scanf("%d", &inputNum);
    printf("Decimal: %d\n", inputNum);
    printf("Octal: %o\n", inputNum);
    printf("Hexadecimal : %X\n", inputNum);

    return 0;
}
