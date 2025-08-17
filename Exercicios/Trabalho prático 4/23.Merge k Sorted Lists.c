#include <stdio.h>
#include <stdlib.h>
// Definition for singly-linked list.
struct ListNode
{
  int val;
  struct ListNode *next;
};
struct ListNode *mergeKLists(struct ListNode **lists, int c);

int main(int argc, char const *argv[])
{
  struct ListNode *lista1 = malloc(sizeof(struct ListNode) * 3);
  lista1[0].val = 1;
  lista1[0].next = &lista1[1];
  lista1[1].val = 4;
  lista1[1].next = &lista1[2];
  lista1[2].val = 5;
  lista1[2].next = NULL;

  struct ListNode *lista2 = malloc(sizeof(struct ListNode) * 3);
  lista2[0].val = 1;
  lista2[0].next = &lista2[1];
  lista2[1].val = 3;
  lista2[1].next = &lista2[2];
  lista2[2].val = 4;
  lista2[2].next = NULL;

  struct ListNode *lista3 = malloc(sizeof(struct ListNode) * 2);
  lista3[0].val = 2;
  lista3[0].next = &lista3[1];
  lista3[1].val = 6;
  lista3[1].next = NULL;

  struct ListNode **listas = malloc(sizeof(struct ListNode *) * 3);
  listas[0] = lista1;
  listas[1] = lista2;
  listas[2] = lista3;

  struct ListNode *head = mergeKLists(listas, 3);
  while (head != NULL)
  {
    printf("%d ", head->val);
    head = head->next;
  }
  printf("\n");
  return 0;
}

// Função auxiliar para trocar ponteiros
void swap(struct ListNode **a, struct ListNode **b)
{
  struct ListNode *tmp = *a;
  *a = *b;
  *b = tmp;
}

// Função para ajustar o heap (min-heap)
void heapify(struct ListNode **heap, int n, int i)
{
  int smallest = i;
  int l = 2 * i + 1;
  int r = 2 * i + 2;
  if (l < n && heap[l]->val < heap[smallest]->val)
    smallest = l;
  if (r < n && heap[r]->val < heap[smallest]->val)
    smallest = r;
  if (smallest != i)
  {
    swap(&heap[i], &heap[smallest]);
    heapify(heap, n, smallest);
  }
}

struct ListNode *mergeKLists(struct ListNode **lists, int k)
{
  // Conta quantas listas não são NULL
  int heapSize = 0;
  for (int i = 0; i < k; i++)
    if (lists[i])
      lists[heapSize++] = lists[i];

  // Cria o heap inicial
  for (int i = heapSize / 2 - 1; i >= 0; i--)
    heapify(lists, heapSize, i);

  struct ListNode dummy;
  struct ListNode *tail = &dummy;
  dummy.next = NULL;

  while (heapSize > 0)
  {
    // Pega o menor nó do heap (raiz)
    struct ListNode *minNode = lists[0];
    tail->next = minNode;
    tail = tail->next;

    // Se houver próximo, substitui a raiz e ajusta o heap
    if (minNode->next)
    {
      lists[0] = minNode->next;
    }
    else
    {
      // Remove a raiz do heap
      lists[0] = lists[--heapSize];
    }
    heapify(lists, heapSize, 0);
  }
  tail->next = NULL;
  return dummy.next;
}