#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* longestNiceSubstring(char* s);
int main() {
  char* s = "YazaAay";
  printf("%s \n", longestNiceSubstring(s));
}

char* longestNiceSubstring(char* s) {
  int i, len = strlen(s), j = 0;
  char* res = malloc(sizeof(char) * len + 1);
  for (i = 0; i < len; i++) {
    printf("%c ", s[i]);
    if (s[i] == (s[i + 1] - 32) || s[i] == (s[i + 1]) + 32) {
      res[j] = s[i];
      j++;
      res[j] = s[i + 1];
    }
  }
  return res;
}
