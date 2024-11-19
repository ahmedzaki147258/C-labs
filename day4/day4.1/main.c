#include <stdio.h>
#include <stdlib.h>

#define ROW 3
#define COL 4

int main()
{
    int arr2d[ROW][COL];
    int sum[ROW], sumOfRow = 0;
    float avg[COL], avgOfColumn;

    for(int i=0;i<ROW;++i){
        for(int j=0;j<COL;++j){
            printf("Enter number for [%d][%d]: ", i + 1, j + 1);
            while (!scanf("%d", &arr2d[i][j])) {
                printf("Invalid input, Enter number for [%d][%d]: ", i + 1, j + 1);
                while (getchar()!='\n');
            }
        }
    }

    for(int i=0;i<ROW;i++){
        for(int j=0;j<COL;j++){
            sumOfRow += arr2d[i][j];
        }
        sum[i] = sumOfRow;
        sumOfRow = 0;
    }

    for(int j=0;j<COL;j++){
        for(int i=0;i<ROW;i++){
            sumOfRow += arr2d[i][j];
        }
        avg[j] = (float)sumOfRow / ROW;
        sumOfRow = 0;
    }

    printf("\nSum of each Row:\n");
    for (int i = 0; i < ROW; i++) {
        printf("Row %d: %d\n", i + 1, sum[i]);
    }

    printf("\nAverage of each Column:\n");
    for (int j = 0; j < COL; j++) {
        printf("Column %d: %.2f\n", j + 1, avg[j]);
    }

    return 0;
}
