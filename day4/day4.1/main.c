#include <stdio.h>
#include <stdlib.h>
#define ROW 3
#define COL 4

int main()
{
    char check;
    float avg[COL], avgOfColumn;
    int arr2d[ROW][COL], sum[ROW], sumOfRow = 0, flag = 1;

    for(int i=0;i<ROW;++i){ // validation
        for(int j=0;j<COL;++j){
            flag = 1;
            while (flag) {
                printf("Enter number for [%d][%d]: ", i + 1, j + 1);
                if (scanf("%d%c", &arr2d[i][j], &check) && check == '\n') {
                    flag = 0;
                } else {
                    printf("Invalid input, ");
                    while (getchar() != '\n');
                }
            }
        }
    }

    for(int i=0;i<ROW;i++){ // calc Sum.
        for(int j=0;j<COL;j++){
            sumOfRow += arr2d[i][j];
        }
        sum[i] = sumOfRow;
        sumOfRow = 0;
    }

    for(int j=0;j<COL;j++){ // calc Avg.
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
