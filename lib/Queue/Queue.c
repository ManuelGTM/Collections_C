#include "Queue.h"
#include "../Node/Node.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

bool is_queue_empty(Queue *q) { return q->front == NULL; }

Queue *initialize_queue() {

  Queue *q = (Queue *)malloc(sizeof(Queue));
  q->front = q->rear = NULL;

  return q;
}

void enqueue(Queue *q, int data) {

  Node *new = create_node(data);

  if (is_queue_empty(q)) {
    q->front = new;
    q->rear = q->front;
  }

  q->rear->next = new;
  q->rear = new;
}

void dequeue(Queue *q) {

  if (is_queue_empty(q)) {
    printf("The queue is empty!!");
  }

  Node *temp = q->front;
  q->front = q->front->next;
  free(temp);
}

int peek_front(Queue *q) { return q->front->data; }
int peek_rear(Queue *q) { return q->rear->data; }

void show_queue(Queue *q) {
  printf("\n------------------------------------------\n");
  printf("\t\t Queue");
  printf("\n------------------------------------------\n");

  Node *current = q->front;

  if (is_queue_empty(q)) {

    printf("The queue is empty!!");
  }
  int count = 1;

  while (current != NULL) {

    printf("position %d: %d\n", count, current->data);

    current = current->next;
    count++;
  }

  printf("\n%d elements in the queue", count);
}
