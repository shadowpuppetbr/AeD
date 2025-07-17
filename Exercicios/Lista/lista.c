#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int q_head;
  int q_tail;
  int* queue;
} MyCircularQueue;

MyCircularQueue* myCircularQueueCreate(int k) {
  MyCircularQueue* obj = malloc(sizeof(MyCircularQueue));
  int* queue = malloc(sizeof(int) * k);
  obj->q_head = -1;
  obj->q_tail = -1;
  obj->queue = queue;
  return obj;
}

bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
  int head = obj->q_head;
  int tail = obj->q_tail;
  if (head == -1 || head == tail) {
    return true;
  }
  return false;
}

bool myCircularQueueIsFull(MyCircularQueue* obj) {
  int head = obj->q_head;
  int tail = obj->q_tail;
  if (head == tail) {
    return true;
  }
  return false;
}

bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
  // primeiro enqueue
  if (myCircularQueueIsEmpty(obj)) {
    obj->q_head = 0;
    obj->q_tail = 0;
  } else if (myCircularQueueIsFull(obj)) {
    printf("\nError: can't enqueue, it's full");
    return false;
  }
  obj->queue[obj->q_tail] = value;
  obj->q_tail++;
  return true;
}

bool myCircularQueueDeQueue(MyCircularQueue* obj) {
  int* head = &obj->q_head;
  int* tail = &obj->q_tail;

  if (myCircularQueueIsEmpty(obj)) {
    printf("\nError: can't enqueue, it's empty");
    return false;
  }
  *head++;

  return true;
}

int myCircularQueueFront(MyCircularQueue* obj) { return obj->q_head; }

int myCircularQueueRear(MyCircularQueue* obj) { return obj->q_tail; }

void myCircularQueueFree(MyCircularQueue* obj) {
  free(obj->queue);
  free(obj);
}

int main(int argc, char const* argv[]) {
  int k;
  scanf("%d", &k);

  MyCircularQueue* obj = myCircularQueueCreate(k);
  for (int i = 0; i < k - 2; i++) {
    printf(" %d ", myCircularQueueEnQueue(obj, i));
  }
  printf("\n");

  for (int i = 0; i < k; i++) {
    printf("| %d ", obj->queue[i]);
  }
  printf("|\n");

  for (int i = 0; i < k; i++) {
    printf(" %d ", myCircularQueueEnQueue(obj, i));
  }
  printf("\n");

  for (int i = 0; i < k; i++) {
    printf("| %d ", obj->queue[i]);
  }
  printf("|\n");

  bool param_2 = myCircularQueueDeQueue(obj);

  int param_3 = myCircularQueueFront(obj);

  int param_4 = myCircularQueueRear(obj);

  bool param_5 = myCircularQueueIsEmpty(obj);

  bool param_6 = myCircularQueueIsFull(obj);

  printf(
      "\nDequeue: %d\nFront: %d\nRear: %d\nIsEmpty: %d\nIsFull: "
      "%d\n",
      param_2, param_3, param_4, param_5, param_6);

  myCircularQueueFree(obj);
}

/**
 * Your MyCircularQueue struct will be instantiated and called as such:
 * MyCircularQueue* obj = myCircularQueueCreate(k);
 * bool param_1 = myCircularQueueEnQueue(obj, value);

 * bool param_2 = myCircularQueueDeQueue(obj);

 * int param_3 = myCircularQueueFront(obj);

 * int param_4 = myCircularQueueRear(obj);

 * bool param_5 = myCircularQueueIsEmpty(obj);

 * bool param_6 = myCircularQueueIsFull(obj);

 * myCircularQueueFree(obj);
*/