#include<stdio.h>
#include<string.h>

int exist(char** board, int boardSize, int* boardColSize, char* word);
int main() {
    char* board[3][4] = { {"ABCE"},{"SFCS"},{"ADEE"} };
    char* word = "ABCEEEE";
    int boardColSize = 4;

    printf("\n%d\n", exist(*board, 3, &boardColSize, word));
}

int exist(char** board, int boardSize, int* boardColSize, char* word) {
    int i = 0, j = 0;
    char letter;
    printf("%d %d\n", boardSize, *boardColSize);
    char* lineWord = board[i];
    int isOK = 0;

    for (j = 0; j < strlen(word); j++) {

        while (i <= *boardColSize * boardSize + 1) {
            letter = *lineWord++;
            printf("%c", letter);
            if (letter == word[j]) {
                isOK = 1;
                break;
            }
            i++;
        }
        if (isOK == 0) {
            return 0;
        }
        else { isOK = 0; }
    }
    return 1;
}