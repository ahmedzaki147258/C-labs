#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED



#endif // HEADER_H_INCLUDED
void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int decr(int size, int curr) {
    return (curr - 1 + size) % size;
}

int incr(int size, int curr) {
    return (curr + 1) % size;
}

// Write a C program to implement the algorithm of the Magic Box puzzle.
void task1(){
    int size;
    printf("Enter the size of the magic square (odd number): ");
    scanf(" %d", &size);
    if(size % 2 == 0 || size < 0){
        printf("Size must be an odd positive number\n");
    } else {
        int row = 0, col = size / 2;

        gotoxy(col * 4 + 5, row + 3);
        printf("%d", 1);

        for (int i = 2; i <= size * size; i++) {
            if ((i - 1) % size != 0) {
                row = decr(size, row); // to up
                col = decr(size, col); // to left
            } else {
                row = incr(size, row); // to down
                // col = incr(size, col); // to right
            }

            gotoxy(col * 4 + 5, row + 3);
            printf("%d", i);
            Sleep(300);
        }
        gotoxy(0, size + 4);
        printf("Magic Box Completed!\n");
    }
}

// Write a C program to receive numbers from the user, and exit when the sum exceeds 100.
void task2(){
    int sum = 0;
    int number;
    while(6)
    {
        printf("Enter Number: ");
        scanf(" %d", &number);
        sum += number;
        if(sum>100)
            break;
    }
    printf("total sum: %d\n", sum);
}

// Write a C program to print a simple menu with 3 choices, when select one choice print the choice word and exit.
void task3(){
    printf("Simple Menu:\n");
    printf("A. Pasta\n");
    printf("B. Fried Chicken\n");
    printf("C. Crepe\n");
    printf("Enter your choice (A-C): ");
    char choice;
    scanf(" %c", &choice);

    switch(choice){
        case 'A':
        case 'a':
            printf("You selected: Pasta\n");
            break;
        case 'B':
        case 'b':
            printf("You selected: Fried Chicken\n");
            break;
        case 'C':
        case 'c':
            printf("You selected: Crepe\n");
            break;
        default:
            printf("Invalid choice!\n");
    }
}

// Write a C program to print the multiplication table in ascending order from table 1 to table 10 sequentially and separated by group of “ *’s ”.
void task4(){
    for(int i=1;i<=10;i++){
        printf("Multiplication Table of %d:\n", i);
        for(int j=1;j<=12;j++){
            printf("%d x %d = %d\n", i, j, i*j);
        }

        if(i!=10){
            printf("\n");
            printf("*******************************\n");
        }
    }
}

// Rewrite the previous program to print them in descending order.
void task5(){
    for(int i=10;i>=1;--i){
        printf("Multiplication Table of %d:\n", i);
        for(int j=1;j<=12;j++){
            printf("%d x %d = %d\n", i, j, i*j);
        }

        if(i!=1){
            printf("\n");
            printf("*******************************\n");
        }
    }
}
