#ifndef STACK_H
#define STACK_H

#include "../Node/Node.h"
#include <stdbool.h>

typedef struct Stack {
  Node *top;
} Stack;

typedef struct CharStack {
  CharNode *top;
} CharStack;

Stack *initialize_stack();
CharStack *initialize_char_stack();

void push(Stack *s, int data);
void push_char(CharStack *s, char *c);
int pop(Stack *s);

int peek_stack(Stack *s);
void show_stack(Stack *s);

bool is_stack_empty(Stack *s);

#endif // !STACK_H
