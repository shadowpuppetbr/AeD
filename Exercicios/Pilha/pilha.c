#include <stdio.h>
#include <stdlib.h>

typedef struct pilha {
  int base;
  int topo;
  int max;
  void* data;
} pilha;
pilha* criaPilha(int size);
void push(pilha* p, int x);
int pop(pilha* p);

int main() {
  pilha* pilha = criaPilha(100);
  push(pilha, 4);

  return 0;
}

int pop(pilha* p) { p->topo--; }

void push(pilha* p, int x) {
  int* valor = malloc(sizeof(int));
  valor = x;
  if (p->max > p->topo) {
    p->data = valor;
    p->topo++;
  }
}

pilha* criaPilha(int size) {
  pilha* p = malloc(sizeof(pilha));
  p->base = 0;
  p->topo = 0;
  p->max = size;
  p->data = NULL;
  return p;
}