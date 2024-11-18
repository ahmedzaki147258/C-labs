#include <stdio.h>
#include <stdlib.h>
#define SIZE 100

int main()
{
    int arr[SIZE], flag = 1;
    int sizeOfArray, rows, cols;

    do {
        printf("Enter size of array: ");
        scanf(" %d", &sizeOfArray);
        if (sizeOfArray < 0 || sizeOfArray > SIZE) {
            printf("Invalid size! Try again.\n");
        }
    } while (sizeOfArray < 0 || sizeOfArray > SIZE);

    for (int i = 0; i < sizeOfArray; i++) {
        printf("Enter number %d: ", i + 1);
        scanf(" %d", &arr[i]);
    }

    do {
        printf("Enter number of rows: ");
        scanf(" %d", &rows);
        if (sizeOfArray % rows == 0){
            cols = sizeOfArray / rows;
            flag = 0;
        } else {
            printf("Cannot divide %d elements into %d rows evenly.\n", sizeOfArray, rows);
        }
    } while (flag);

    printf("\noutput:\n");
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            printf("%d \t", arr[i*cols+j]);
        }
        printf("\n");
    }

    return 0;
}
