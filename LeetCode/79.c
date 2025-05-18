/*
# Gustavo dos Santos Leon - M2
# 79. Word Search
Given an m x n grid of characters board and a string word, return true if word
exists in the grid.

The word can be constructed from letters of sequentially adjacent cells, where
adjacent cells are horizontally or vertically neighboring. The same letter cell
may not be used more than once.

Example 1:
Input: board = [
    ["A","B","C","E"],
    ["S","F","C","S"],
    ["A","D","E","E"]],
word = "ABCCED" Output: true

Example 2:
Input: board = [
    ["A","B","C","E"],
    ["S","F","C","S"],
    ["A","D","E","E"]],
word = "SEE" Output: true

Example 3:
Input: board = [
    ["A","B","C","E"],
    ["S","F","C","S"],
    ["A","D","E","E"]],
word = "ABCB" Output: false

Constraints:

m == board.length
n = board[i].length
1 <= m, n <= 6
1 <= word.length <= 15
board and word consists of only lowercase and uppercase English letters.

Follow up: Could you use search pruning to make your solution faster with a
larger board?
*/
#include <stdio.h>
#include <string.h>

int exist(char **board, int boardSize, int *boardColSize, char *word);
int dfs(char **board, int row, int max_row, int collum, int max_collum,
        char *word, int w_index, int w_len);

int main() {
  char boardData[3][5] = {"ABCE", "SFCS", "ADEE"};  // +1 para '\0'
  char *board[3] = {boardData[0], boardData[1], boardData[2]};
  char *word = "ABCB";
  int boardColSize = 4;

  printf("\n%d\n", exist(board, 3, &boardColSize, word));
}

int exist(char **board, int boardSize, int *boardColSize, char *word) {
  int w_index = 0, w_len = strlen(word);
  for (int i = 0; i < boardSize; i++) {
    for (int j = 0; j < *boardColSize; j++) {
      if (dfs(board, i, boardSize, j, *boardColSize, word, w_index, w_len)) {
        return 1;
      }
    }
  }
  return 0;
}

int dfs(char **board, int row, int max_row, int collum, int max_collum,
        char *word, int w_index, int w_len) {
  int res = 0;
  if (w_len == w_index) {
    return 1;
  }
  if (row >= max_row || collum >= max_collum || row < 0 || collum < 0 ||
      board[row][collum] != word[w_index]) {
    return 0;
  }

  board[row][collum] = '#';

  res = (dfs(board, row, max_row, collum + 1, max_collum, word, w_index + 1,
             w_len) ||
         dfs(board, row, max_row, collum - 1, max_collum, word, w_index + 1,
             w_len) ||
         dfs(board, row + 1, max_row, collum, max_collum, word, w_index + 1,
             w_len) ||
         dfs(board, row - 1, max_row, collum, max_collum, word, w_index + 1,
             w_len));

  board[row][collum] = word[w_index];

  return res;
}
