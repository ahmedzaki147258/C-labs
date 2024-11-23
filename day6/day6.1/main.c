#include <stdio.h>
#include <conio.h>
#include <string.h>

#define SIZE 100
#define LEFT 75
#define RIGHT 77
#define HOME 71
#define END 81 //(PAGEDOWN -> 81) - (END -> 79)
#define INSERT 82
#define DELETE 83
#define BACKSPACE 8
#define EXTENDED 224

void printEditor(char input[], char *curr) {
    system("cls");
    printf("%s\n", input);
    int position = curr - input; // current - beginningOfArray
    for (int i = 0; i < position; i++) {
        printf(" ");
    }
    printf("^\n");
}

int main() {
    char input[SIZE] = "";
    char *head = input;
    char *tail = input;
    char *curr = input;
    printEditor(input, curr);

    while (1) {
        int ch = getch();
        if (ch == EXTENDED) {
            ch = getch();
            switch (ch) {
                case LEFT:
                    if (curr > head) curr--;
                    break;
                case RIGHT:
                    if (curr < tail) curr++;
                    break;
                case HOME:
                    curr = head;
                    break;
                case END:
                    curr = tail;
                    break;
                case DELETE:
                    if (curr < tail) {
                        for (int i = curr - input; i < strlen(input); i++) {
                            input[i] = input[i + 1];
                        }
                        tail--;
                    }
                    break;
            }
        } else if (ch == BACKSPACE) {
            if (curr > head) {
                for(int i = curr - input - 1; i < strlen(input); i++){
                    input[i] = input[i + 1];
                }
                curr--;
                tail--;
            }
        } else if (ch == INSERT) {

        } else {
            if (strlen(input) < SIZE - 1) { // -1 for '\0'
                for (int i = strlen(input); i >= (curr - input); i--) {
                    input[i + 1] = input[i];
                }
                *curr = ch;
                curr++;
                tail++;
            }
        }

        printEditor(input, curr);
    }

    return 0;
}
