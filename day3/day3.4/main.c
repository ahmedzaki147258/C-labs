#include <stdio.h>
#include <stdlib.h>
#define SIZE 100

int main()
{
    int arr[SIZE], sizeOfArray, min, max;

    do {
        printf("Enter size of array: ");
        scanf("%d", &sizeOfArray);
        if (sizeOfArray < 1 || sizeOfArray > SIZE) {
            printf("Invalid size! Try again.\n");
        }
    } while (sizeOfArray < 1 || sizeOfArray > SIZE);

    for (int i = 0; i < sizeOfArray; i++) {
        printf("Enter number %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    min = max = arr[0];
    for (int i = 0; i < sizeOfArray; i++) {
        if(arr[i] < min)
            min = arr[i];
        if(arr[i] > max)
            max = arr[i];
    }
    printf("min: %d - max: %d\n", min, max);
    return 0;
}
