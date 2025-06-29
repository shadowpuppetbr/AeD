#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char c;
  int qtd;
} Item;

typedef struct {
  int head;
  int end;
  int capacity;
  Item* q;
} Queue;

char* longestDiverseString(int a, int b, int c);
bool enqueue(Queue* queue, char letter, int qnt);
Item dequeue(Queue* queue);
Queue* new_queue(int capacity);

int main() {
  int a = 1, b = 1, c = 7;
  char* string = longestDiverseString(a, b, c);
  printf("%s\n", string);
  free(string);
}

char* longestDiverseString(int a, int b, int c) {
  int index = 0;
  char* s = '\0';
  Queue* queue = new_queue(3);

  enqueue(queue, 'a', a);
  enqueue(queue, 'b', b);
  enqueue(queue, 'c', c);

  while (queue->end > 0) {
    Item item = dequeue(queue);
    if (index >= 2 && s[index - 1] == item.c && s[index - 2] == item.c) {
      if (queue->end == 0) {
        break;
      }
      Item next = dequeue(queue);
      if (next.qtd == 0) {
        break;
      }
      enqueue(queue, item.c, item.qtd);
      item = next;
    }
    s = realloc(s, (index + 2) * sizeof(char));
    s[index++] = item.c;
    s[index] = '\0';
    if (item.qtd > 1) {
      enqueue(queue, item.c, item.qtd - 1);
    }
  }
  free(queue->q);
  free(queue);
  return s;
}

Queue* new_queue(int capacity) {
  Queue* sentinel = malloc(sizeof(Queue));
  sentinel->q = malloc((sizeof(Item) * capacity));
  sentinel->head = 0;
  sentinel->end = 0;
  sentinel->capacity = capacity;
  return sentinel;
}

bool enqueue(Queue* queue, char letter, int qtd) {
  if (queue->end >= queue->capacity) {
    return false;
  }
  if (qtd <= 0) {
    return false;
  }
  // inserir no fim
  int i = queue->end;
  queue->q[i].c = letter;
  queue->q[i].qtd = qtd;
  queue->end++;

  while (i > 0) {
    int pai = (i - 1) / 2;
    if (queue->q[i].qtd > queue->q[pai].qtd) {
      Item temp = queue->q[i];
      queue->q[i] = queue->q[pai];
      queue->q[pai] = temp;
      i = pai;
    } else {
      break;
    }
  }

  return true;
}

Item dequeue(Queue* queue) {
  Item vazio = {'\0', 0};

  if (queue->end == 0) {
    return vazio;
  }

  Item topo = queue->q[0];

  queue->end--;
  queue->q[0] = queue->q[queue->end];
  int i = 0;
  while (1) {
    int maior = i;
    int esq = 2 * i + 1;
    int dir = 2 * i + 2;
    if (esq < queue->end && queue->q[esq].qtd > queue->q[maior].qtd) {
      maior = esq;
    }
    if (dir < queue->end && queue->q[dir].qtd > queue->q[maior].qtd) {
      maior = dir;
    }
    if (maior == i) {
      break;
    }

    Item temp = queue->q[i];
    queue->q[i] = queue->q[maior];
    queue->q[maior] = temp;

    i = maior;
  }
  return topo;
}
