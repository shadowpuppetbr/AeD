#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

// Definition for a binary tree node.
struct TreeNode {
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
};
int checkHeight(struct TreeNode *root) {
  if (root == NULL) {
    return 0;
  }
  int l_height = checkHeight(root->left);
  if (l_height == -1) {
    return -1;
  }
  int r_height = checkHeight(root->right);
  if (r_height == -1) {
    return -1;
  }
  if (abs(l_height - r_height) > 1) {
    return -1;
  }
  if (r_height > l_height) {
    return r_height + 1;
  } else {
    return l_height + 1;
  }
}
bool isBalanced(struct TreeNode *root) {
  if (root == NULL) {
    return true;
  } else
    return checkHeight(root) != -1;
}
int main(int argc, char const *argv[]) {
  struct TreeNode node7 = {4, NULL, NULL};
  struct TreeNode node6 = {4, NULL, NULL};
  struct TreeNode node5 = {3, NULL, NULL};
  struct TreeNode node4 = {3, &node6, &node7};
  struct TreeNode node3 = {2, NULL, NULL};
  struct TreeNode node2 = {2, &node4, &node5};
  struct TreeNode node1 = {1, &node2, &node3};
  printf("%d ", isBalanced(&node1));
  return 0;
}
