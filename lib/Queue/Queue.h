#ifndef QUEUE_H
#define QUEUE_H

#include "../Node/Node.h"
#include "stdbool.h"

typedef struct {

  Node *front;
  Node *rear;

} Queue;

Queue *initialize_queue();
void enqueue(Queue *q, int data);
void dequeue(Queue *q);
void show_queue(Queue *q);
int peek_front(Queue *q);
int peek_rear(Queue *q);
bool is_queue_empty(Queue *q);

#endif // !QUEUE_H
