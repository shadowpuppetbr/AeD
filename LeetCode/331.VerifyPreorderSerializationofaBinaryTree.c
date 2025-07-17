#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

/* void preorder(struct TreeNode* root, int** result, int* returnSize) {
  if (root) {
    *result = realloc(*result, sizeof(int) * (*returnSize + 1));
    (*result)[*returnSize] = root->val;
    (*returnSize)++;
    preorder(root->left, result, returnSize);
    preorder(root->right, result, returnSize);
  }
}

int* preorderTraversal(struct TreeNode* root, int* returnSize) {
  *returnSize = 0;
  int* result = NULL;
  preorder(root, &result, returnSize);
  return result;
}
 */

bool isValidSerialization(char* preorder) {
  // TODO
}
int main(int argc, char const* argv[]) {
  char preorder1[13] = "9,3,4,#,#,1,#,#,2,#,6,#,#";
  int size = 0;
  int* result = isValidSerialization(preorder1);

  for (int i = 0; i < size; i++) {
    printf("%d ", result[i]);
  }
  free(result);
  return 0;
}
