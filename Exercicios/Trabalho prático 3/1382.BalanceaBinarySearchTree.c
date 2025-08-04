// Gustavo dos Santos Leon - M2
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// Definition for a binary tree node.
struct TreeNode
{
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
};
struct TreeNode *balanceBST(struct TreeNode *root);
void TreeNodeToArray(struct TreeNode *node, int *array, int *index);
void insertNode(struct TreeNode *node, int value);
struct TreeNode *createTree(int *array, int max, int min);

int main()
{
  struct TreeNode node4 = {4, NULL, NULL};
  struct TreeNode node3 = {3, NULL, &node4};
  struct TreeNode node2 = {2, NULL, &node3};
  struct TreeNode node1 = {1, NULL, &node2};

  struct TreeNode *balanced = balanceBST(&node1);
  free(balanced);
  return 0;
}

struct TreeNode *createNode(int value)
{
  struct TreeNode *node = malloc(sizeof(struct TreeNode));
  node->val = value;
  node->left = NULL;
  node->right = NULL;
  return node;
}

void TreeNodeToArray(struct TreeNode *node, int *array, int *index)
{
  if (node == NULL)
    return;

  // goes to left sub-tree first
  if (node->left != NULL)
    TreeNodeToArray(node->left, array, index);

  // print or add value to array
  array[*index] = node->val;
  (*index)++;

  // goes to right after
  if (node->right != NULL)
    TreeNodeToArray(node->right, array, index);
}

void insertNode(struct TreeNode *node, int value)
{
  // root vazio
  if (node->val == -1)
  {
    node->val = value;
    return;
  }
  // insere a esqueda
  if (value < node->val)
  { // se o node da esqurda não existir
    if (node->left == NULL)
    {
      node->left = createNode(value);
      return;
    }
    // se node a esquerda exister, for maior que value e tiver um irmão vazio
    if (value < node->left->val && node->right == NULL)
    {
      node->right = createNode(node->val);
      node->val = node->left->val;
      node->left->val = value;
    }
    else
    {
      insertNode(node->left, value);
    }
  }
  // insere a direita
  else
  {
    // se o node da direita não existir
    if (node->right == NULL)
    {
      node->right = createNode(value);
      return;
    }
    // se node a direita exister, for menor que value e tiver um irmão vazio
    if (value > node->right->val && node->left == NULL)
    {
      node->left = createNode(node->val);
      node->val = node->right->val;
      node->right->val = value;
    }
    else
    {
      insertNode(node->right, value);
    }
  }
}

struct TreeNode *createTree(int *array, int max, int min)
{
  int mid = (max - min) / 2 + min;
  int mask = 0;
  if (array[mid] == -1)
  {
    return NULL;
  }
  if (mid == 0)
  {
    struct TreeNode *newTreeRoot = createNode(array[mid]);
    return newTreeRoot;
  }
  else
  {
    struct TreeNode *newTreeRoot = createNode(array[mid]);
    mask = array[mid];
    array[mid] = -1;

    newTreeRoot->left = createTree(array, mid, min);
    newTreeRoot->right = createTree(array, max, mid);

    array[mid] = mask;

    return newTreeRoot;
  }
}

struct TreeNode *balanceBST(struct TreeNode *root)
{
  int index = 0;
  int *array = malloc(sizeof(int) * 10000);
  TreeNodeToArray(root, array, &index);

  struct TreeNode *newTree = createTree(array, index, 0);
  free(array);
  return newTree;
}