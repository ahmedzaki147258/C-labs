#include <stdio.h>
#include <stdlib.h>

int calcPower(int, int);
int main()
{
    int base, exp;
    printf("Enter the base: ");
    scanf(" %d", &base);
    printf("Enter the exp: ");
    scanf(" %d", &exp);
    printf("Result: %d\n", calcPower(base, exp));
    return 0;
}

int calcPower(int base, int exp){
    if(exp == 0){
        return 1;
    }

    int halfPower = calcPower(base, exp / 2);
    if (exp % 2 == 0) {
        return halfPower * halfPower;
    } else {
        return halfPower * halfPower * base;
    }
}
