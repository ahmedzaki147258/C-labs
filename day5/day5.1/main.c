#include <stdio.h>
#include <stdlib.h>
#include "a7med_StringFunctions.c"

int main()
{
    char str1[25] = "A7med zaki";
    char str2[25] = "A7med zaki";

    printf("length: %d\n", stringLength(str1));
    printf("compare: %d\n", stringCompare(str1, str2));

    stringConcat(str1, str2);
    printf("concat: %s\n", str1);

    printf("string before copy: %s\n", str1);
    stringCopy(str1, str2);
    printf("string after copy: %s\n", str1);

    stringToUpper(str1);
    printf("string with UpperCase: %s\n", str1);

    stringToLower(str2);
    printf("string with LowerCase: %s\n", str2);

    return 0;
}
