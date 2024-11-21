#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include "a7med_StringFunctions.c"

#define GREEN 10
#define WHITE 7
#define RED 12
#define BLUE 9
#define PURPLE 13
#define SIZE 4
#define MAX_SIZE 100
#define UP 72
#define DOWN 80
// #define LEFT 75
// #define RIGHT 77
#define HOME 71
#define END 81 //(PAGEDOWN -> 81) - (END -> 79)
#define ESC 27
#define ENTER 13
#define EXTENDED 224

void setcolor(int color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}

void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void exitProgram() {
    system("cls");
    setcolor(RED);
    printf("Exiting...\n");
    setcolor(WHITE);
}

void printMenu(int currentSelection) {
    system("cls");
    printPageTitle("Menu Management");
    gotoxy(0,3);
    char options[SIZE][MAX_SIZE] = { "New", "Display", "Modify", "Exit" };
    for (int i = 0; i < SIZE; i++) {
        if (i == currentSelection) {
            setcolor(PURPLE);
            printf("> ");
        } else {
            setcolor(WHITE);
            printf("  ");
        }
        printf("%s\n", options[i]);
    }
}

void printPageTitle(char text[]){
    setcolor(GREEN);
    int startColumn = (MAX_SIZE - stringLength(text)) / 2;
    gotoxy(startColumn, 0);
    for (int i = 0; i < stringLength(text); i++) {
        printf("%c ", text[i]);
    }
}

typedef struct Employee{
    int code;
    char name[MAX_SIZE];
    int netSalary;
} Employee;

int main()
{
    char check;
    int ch, flag = 1, currentSelection = 0, numOfStoredEmployee = 0;
    Employee employee[MAX_SIZE];

    while (1) {
        printMenu(currentSelection);

        ch = getch();
        if (ch == EXTENDED) {
            ch = getch();
            switch (ch) {
                case UP:
                    currentSelection = (currentSelection - 1 + SIZE) % SIZE;
                    break;
                case DOWN:
                    currentSelection = (currentSelection + 1) % SIZE;
                    break;
                case HOME:
                    currentSelection = 0;
                    break;
                case END:
                    currentSelection = SIZE - 1;
                    break;
            }
        } else if (ch == ENTER) {
            system("cls");
            switch (currentSelection) {
                case 0:
                    printPageTitle("Add New Employee");
                    flag = 1;
                    gotoxy(0, 1);
                    setcolor(WHITE);
                    int numberOfEmployees;

                    while (flag) {
                        printf("How many employees do you want to add (or press 'x' to exit)? ");
                        char input[10];
                        scanf("%s", input);

                        if (stringCompare(input, "x") == 0 || stringCompare(input, "X") == 0) {
                            printMenu(currentSelection);
                            flag = 0;
                        }

                        numberOfEmployees = atoi(input); // convert input to number
                        if (numberOfEmployees > 0) {
                            flag = 0;
                        } else if(flag) {
                            printf("Invalid input. Please enter a valid number greater than 0 or 'x' to exit.\n");
                        }
                    }

                    flag = 1;
                    int currentNumberOfEmployee = numOfStoredEmployee;
                    for (int i = currentNumberOfEmployee; i < currentNumberOfEmployee + numberOfEmployees && flag == 1; i++) {
                        int codeValid = 0, salaryValid = 0, nameValid = 0;

                        while (!codeValid) { // validation code
                            printf("Enter code for employee %d: ", i + 1);
                            if (scanf("%d%c", &employee[i].code, &check) == 2 && check == '\n') {
                                if (employee[i].code < 1) {
                                    printf("Invalid input. Code must be a positive number.\n");
                                } else {
                                    int isDuplicate = 0;
                                    for (int j = 0; j < numOfStoredEmployee; j++) {
                                        if (employee[i].code == employee[j].code && isDuplicate == 0) isDuplicate = 1;
                                    }
                                    if (isDuplicate) printf("Code already exists. Please enter a unique code.\n");
                                    else codeValid = 1;
                                }
                            } else {
                                printf("Invalid input. Code must be a valid number.\n");
                                while (getchar() != '\n');
                            }
                        }

                       while (!nameValid) { // validation name
                            printf("Enter name for employee %d (minimum 2 characters): ", i + 1);
                            scanf("%[^\n]", &employee[i].name);
                            if (stringLength(employee[i].name) < 2) {
                                printf("Invalid name. Please enter at least 2 characters.\n");
                            } else {
                                nameValid = 1;
                            }
                            getchar();
                        }

                        while (!salaryValid) { // validation salary
                            printf("Enter net salary for employee %d: ", i + 1);
                            if (scanf("%d%c", &employee[i].netSalary, &check) == 2 && check == '\n') {
                                if (employee[i].netSalary < 1) {
                                    printf("Invalid input. NetSalary must be a positive number.\n");
                                } else {
                                    salaryValid = 1;
                                }
                            } else {
                                printf("Invalid input. NetSalary must be a valid number.\n");
                                while (getchar() != '\n');
                            }
                        }

                        numOfStoredEmployee++;
                        printf("\nEmployee %d added successfully.\n", i + 1);

                        if(numOfStoredEmployee - currentNumberOfEmployee < numberOfEmployees){
                            char continueAdding;
                            printf("Do you want to continue adding employees? (y/n): ");
                            scanf("%c", &continueAdding);
                            if (continueAdding == 'n' || continueAdding == 'N') {
                                printMenu(currentSelection);
                                flag = 0;
                            }
                        }
                        printf("\n");
                    }
                    break;

                case 1:
                    printPageTitle("Display Employees");
                    gotoxy(0, 1);
                    setcolor(BLUE);
                    printf("Employee Details\n");
                    for (int i = 0; i < numOfStoredEmployee; i++) {
                        setcolor(PURPLE);
                        printf("Employee%d\n", i + 1);
                        setcolor(WHITE);
                        printf("Code: %d\n", employee[i].code);
                        printf("Name: %s\n", employee[i].name);
                        printf("NetSalary: %d\n\n", employee[i].netSalary);
                    }
                    break;

                case 2:
                    printPageTitle("Modify Employees");
                    gotoxy(0, 1);
                    setcolor(BLUE);
                    printf("Employee Codes\n");
                    setcolor(WHITE);
                    for (int i = 0; i < numOfStoredEmployee; i++) {
                        printf("Employee%d\n", i + 1);
                        printf("Code: %d\n\n", employee[i].code);
                    }

                    flag = 1;
                    int modifyCode;
                    while (flag) {
                        printf("Enter the code of the employee you want to modify (or press 'x' to exit): ");
                        char input[10];
                        scanf("%s", input);
                        if (stringCompare(input, "x") == 0 || stringCompare(input, "X") == 0) {
                            printMenu(currentSelection);
                            flag = 0;
                        }

                        int modifyCode = atoi(input); // convert input to number
                        if (modifyCode > 0) {
                            int found = 0;
                            for (int i = 0; i < numOfStoredEmployee; i++) {
                                if (employee[i].code == modifyCode) {
                                    found = 1;
                                    char choice;

                                    printf("Do you want to modify the name (n) or salary (s)? ");
                                    scanf(" %c", &choice);

                                    if (choice == 'n' || choice == 'N') {
                                        int nameValid = 0;
                                        while (!nameValid) {
                                            printf("Enter the new name (minimum 2 characters): ");
                                            getchar();
                                            scanf("%[^\n]", &employee[i].name);
                                            if (stringLength(employee[i].name) < 2) {
                                                printf("Invalid name. Please enter at least 2 characters.\n");
                                            } else {
                                                nameValid = 1;
                                                printf("Name updated successfully.\n");
                                            }
                                        }
                                    } else if (choice == 's' || choice == 'S') {
                                        int salaryValid = 0;
                                        while (!salaryValid) {
                                            printf("Enter the new net salary: ");
                                            scanf("%d", &employee[i].netSalary);
                                            if (employee[i].netSalary > 0) {
                                                salaryValid = 1;
                                                printf("NetSalary updated successfully.\n");
                                            } else {
                                                printf("Invalid input. NetSalary must be a positive number.\n");
                                            }
                                        }
                                    } else {
                                        printf("Invalid choice.\n");
                                    }
                                }
                            }

                            if (!found) {
                                printf("Employee with code %d not found. Please enter a valid code.\n", modifyCode);
                            }
                        } else if(flag) {
                            printf("Invalid input. Please enter a valid code.\n");
                        }
                        printf("\n");
                    }
                    break;
                case 3:
                    exitProgram();
                    return 0;
            }
            getch();
        } else if (ch == ESC){
            exitProgram();
            return 0;
        }
    }
    return 0;
}
