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
    if(exp % 2 == 0){
        return calcPower(base, exp/2) * calcPower(base, exp/2);
    } else {
        return calcPower(base, exp/2) * calcPower(base, exp/2) * base;
    }
}
