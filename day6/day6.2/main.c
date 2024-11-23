#include <stdio.h>
#include <stdlib.h>

void swap1(int *a, int *b){ // Arithmetic Operations using (+,-)
    *a += *b;
    *b = *a - *b;
    *a -= *b;
}
void swap2(int *a, int *b){ // Arithmetic Operations using (*,/)
    if(*a == 0 || *b == 0){
        int temp = *b;
        *b = *a;
        *a = temp;
    } else {
        *a *= *b;
        *b = *a / *b;
        *a /= *b;
    }
}
void swap3(int *a, int *b){ // Bitwise XOR
    *a = *a ^ *b;
    *b = *a ^ *b;
    *a = *a ^ *b;
}

int main()
{
    int a = 0, b = 7;
    printf("Before swap a: %d, b: %d\n", a, b);
    swap2(&a, &b);
    printf("After  swap a: %d, b: %d\n", a, b);
    return 0;
}
