#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

// Definition for a binary tree node.
struct TreeNode {
  int val;
  struct TreeNode* left;
  struct TreeNode* right;
};

void preorder(struct TreeNode* root, int** result, int* returnSize) {
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

int main(int argc, char const* argv[]) {
  struct TreeNode node3 = {3, NULL, NULL};
  struct TreeNode node2 = {2, &node3, NULL};
  struct TreeNode node1 = {1, NULL, &node2};
  int size = 0;
  int* result = preorderTraversal(&node1, &size);

  for (int i = 0; i < size; i++) {
    printf("%d ", result[i]);
  }
  free(result);
  return 0;
}
