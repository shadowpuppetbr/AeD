#include<stdio.h>
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



struct ListNode *mergeKLists(struct ListNode **lists, int c)
{
  struct ListNode *novaListaRoot = malloc(sizeof(struct ListNode));
  novaListaRoot->next = NULL;
  int menor = 0, deveTerminar = 0, teveValorValido = 1;
  struct ListNode *node = novaListaRoot;

  if (c == 0 || lists[0] == NULL) // se for vazio retorna vazio
    return novaListaRoot;

  while (teveValorValido == 1)
  {
    teveValorValido = 0;
    menor = 0;

    // uma rodada em que verifica qual é o menor dentre os primeiros elementos de cada lista
    for (int i = 0; i < c; i++)
    {
      if (lists[i] != NULL && lists[menor] != NULL)
        if (lists[i]->val <= lists[menor]->val)
        { // se for menor
          teveValorValido = 1;
          menor = i; // atualizo o index do "menor"
        }
    }
    if (teveValorValido == 1 && lists[menor]->val != NULL)
    {
      node->val = lists[menor]->val;     // o "menor" vai para a nova lista
      lists[menor] = lists[menor]->next; // move a cabeça da lista para o próximo

      // Cria um novo node e coloca-o para ser o próximo e torna-o o node atual
      node = node->next = malloc(sizeof(struct ListNode));
      node->next = NULL;
    }
  }
  return novaListaRoot;
}