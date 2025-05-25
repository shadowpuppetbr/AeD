#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* longestNiceSubstring(char* s);
int main() {
  char* s = "YazaAay";
  printf("%s \n", longestNiceSubstring(s));
}

char* longestNiceSubstring(char* s) {
  int i, len = strlen(s), j = 0, start = 0, max = 0;
  char* res = malloc(sizeof(char) * len + 1);
  res[0] = '\0';

  for (i = 0; i < len - 1; i++) {
    for (j = 0; j < len; j++) {
      int minus[26] = {0}, maius[26] = {0};

      for (int k = i; k <= j; k++) {
        if (s[k] >= 'a' && s[k] <= 'z') {
          minus[s[k] - 'a'] = 1;
        } else if (s[k] >= 'A' && s[k] <= 'Z') {
          maius[s[k] - 'A'] = 1;
        }
      }

      int nice = 1;
      for (int l = 0; l < 26; l++) {
        if (minus[l] != maius[l]) {
          nice = 0;
          break;
        }
      }

      if (nice && (j - i + 1) > max) {
        max = j - i + 1;
        start = i;
      }
    }
  }

  if (max == 0) {
    char* vazio = malloc(1);
    vazio[0] = '\0';
    return vazio;
  }

  strncpy(res, s + start, max);
  res[max] = '\0';
  return res;
}
