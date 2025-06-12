#include <stdio.h>
#include <stdlib.h>

int* dailyTemperatures(int* temperatures, int temperaturesSize,
                       int* returnSize);

int main(int argc, char const* argv[]) {
  int test[8] = {73, 74, 75, 71, 69, 72, 76, 73};
  int returnSize = 0;
  int* ans = dailyTemperatures(test, 8, &returnSize);
  for (int i = 0; i < returnSize; i++) {
    printf("%d ", ans[i]);
  }
  printf("\n");
  free(ans);
  return 0;
}

int* dailyTemperatures(int* temperatures, int temperaturesSize,
                       int* returnSize) {
  int* ans = malloc(sizeof(int) * temperaturesSize);
  *returnSize = temperaturesSize;
  int i, j, count = 1;
  for (i = 0; i <= temperaturesSize - 1; i++) {
    j = i + 1;
    count = 1;
    while (temperatures[j] <= temperatures[i]) {
      count++;
      j++;
      if (j >= temperaturesSize) {
        count = 0;
        break;
      }
    }
    ans[i] = count;
  }
  ans[i]=0;
  return ans;
}