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
  struct ListNode *lista1 = malloc(sizeof(struct ListNode) * 1);
  lista1[0].val = 1;
  lista1[0].next = NULL;

  struct ListNode **listas = malloc(sizeof(struct ListNode *) * 2);
  listas[0] = NULL;
  listas[1] = lista1;

  struct ListNode *head = mergeKLists(listas, 2);
  while (head != NULL)
  {
    printf("%d ", head->val);
    head = head->next;
  }
  printf("\n");
  return 0;
}

struct ListNode *mergeKLists(struct ListNode **lists, int c)
{
  struct ListNode *novaListaRoot = malloc(sizeof(struct ListNode));
  novaListaRoot->next = NULL;

  int menor = 0, isFirstIteration = 1, teveValorValido = 1;
  struct ListNode *node;

  if (c == 0 || (c == 1 && lists[0] == NULL)) // se for vazio retorna vazio
    return NULL;

  while (teveValorValido == 1)
  {
    teveValorValido = 0;
    menor = 0;

    // uma rodada em que verifica qual é o menor dentre os primeiros elementos de cada lista
    for (int i = 0; i < c; i++)
    {
      while (lists[menor] == NULL && menor < c - 1)
      {
        menor++;
      }
      if (lists[i] != NULL && lists[i]->val <= lists[menor]->val)
      { // se for menor
        teveValorValido = 1;
        menor = i; // atualizo o index do "menor"
      }
    }
    if (teveValorValido == 1 && lists[menor] != NULL)
    {
      if (isFirstIteration == 1)
      {
        node = novaListaRoot;
        isFirstIteration = 0;
      }
      else
      {
        // Cria um novo node e coloca-o para ser o próximo e torna-o o node atual
        node = node->next = malloc(sizeof(struct ListNode));
        node->next = NULL;
      }
      node->val = lists[menor]->val;     // o "menor" vai para a nova lista
      lists[menor] = lists[menor]->next; // move a cabeça da lista para o próximo
    }
    else if (teveValorValido == 0 && isFirstIteration == 1)
    {
      return NULL;
    }
  }
  return novaListaRoot;
}