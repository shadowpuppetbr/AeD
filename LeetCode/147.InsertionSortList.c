#include<stdlib.h>
#include<stdio.h>

 // Definition for singly-linked list.
 struct ListNode {
     int val;
     struct ListNode *next;
  };

struct ListNode* insertionSort(struct ListNode* sorted, struct ListNode* current);
struct ListNode* insertionSortList(struct ListNode* head);
int main(int argc, char const *argv[])
{
  struct ListNode node1 = {4, NULL}; // tail
  struct ListNode node2 = {2, &node1};
  struct ListNode node3 = {1, &node2};
  struct ListNode node4 = {3, &node3}; // head

  struct ListNode* sorted = insertionSortList(&node4);
  //struct ListNode* sorted = &node4;

  while (sorted != NULL)
  {
    printf("%d ", sorted->val);
    sorted = sorted->next;
  }
  printf("\n");
  return 0;
}


struct ListNode* insertionSortList(struct ListNode* head) {
    struct ListNode* current = head;
    struct ListNode* sorted = NULL;
    // enquanto a minha LinekdList atual não tiver terminado faça:
    while (current != NULL){
        // pega o próximo 
        struct ListNode* next = current->next;
        //remove o atual da lista
        current->next = NULL;
        // pega o node atual e insere na posição correta da NOVA lista
        sorted = insertionSort(sorted, current);
        // avança na lista pegando o próximo e colocando na possição atual
        current = next;
    }

    return sorted;
}

struct ListNode* insertionSort(struct ListNode* sorted, struct ListNode* current){
    /* se a lista estiveer vazia OU se o valor atual for menor do 
    *  que o primeiro valor da lista ordenada
    **/
     if(sorted == NULL || current->val < sorted->val){
        // nesse caso o valor atual deve ir para a primeira 
        // possição da lista ordenada
        current->next = sorted;
        return current;
    }
    // cria um elemento auxiliar para percorrermos a lista ordenada
    struct ListNode* pos = sorted;
    /* enquanto eu não chegar ao fim E o proximo valor da 
    *  lista ordenada ainda for maior que o que eu quero inserir */
    while( pos->next != NULL && pos->next->val < current->val){
        // avança na lista ordenada
        pos = pos->next;
    }
    // posiciono o meu elemento entra o atual e o próimo
    // o 2º elemnto (após o 1º) será o próximo depois do meu elemento atual
    current->next = pos->next;
    // o próximo depois do 1º elemento agora será o que eu quero inserir (atual)
    pos->next = current;

    return sorted;
}