#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

#define GREEN 10
#define WHITE 7
#define RED 12
#define SIZE 3
#define UP 72
#define DOWN 80
// #define LEFT 75
// #define RIGHT 77
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

void printMenu(int currentSelection) {
    system("cls");

    if (currentSelection == 0) {
        setcolor(GREEN);
        printf("New\n");
    } else {
        setcolor(WHITE);
        printf("New\n");
    }

    if (currentSelection == 1) {
        setcolor(GREEN);
        printf("Display\n");
    } else {
        setcolor(WHITE);
        printf("Display\n");
    }

    if (currentSelection == 2) {
        setcolor(GREEN);
        printf("Exit\n");
    } else {
        setcolor(WHITE);
        printf("Exit\n");
    }
}

int main()
{
    int ch;
    int currentSelection = 0;

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
            }
        } else if (ch == ENTER) {
            system("cls");
            switch (currentSelection) {
                case 0:
                    setcolor(GREEN);
                    gotoxy(0,1);
                    printf("you selected New\n");
                    break;
                case 1:
                    setcolor(GREEN);
                    gotoxy(0, 1);
                    printf("you selected Display\n");
                    break;
                case 2:
                    setcolor(RED);
                    printf("Exiting...\n");
                    setcolor(WHITE);
                    return;
            }
            getch();
        } else if (ch == ESC){
            system("cls");
            printMenu(currentSelection);
        }
    }
    return 0;
}
