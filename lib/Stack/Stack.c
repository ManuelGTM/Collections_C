#include "Stack.h"
#include "../Node/Node.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

bool is_stack_empty(Stack *s) { return s->top == NULL; }

Stack *initialize_stack() {
  Stack *s = (Stack *)malloc(sizeof(Stack));
  s->top = NULL;
  return s;
}
CharStack *initialize_char_stack(){
 CharStack *s = (CharStack *)malloc(sizeof(CharStack));
  s->top = NULL;
  return s;
}

void push(Stack *s, int data) {

  Node *new = create_node(data);

  Node *temp = s->top;
  s->top = new;
  s->top->next = temp;
}

void push_char(CharStack *s, char *c){
    CharNode *new = create_char_node(c);
    CharNode *temp = s->top;
    s->top = new;
    s->top->next = temp;
}

int pop(Stack *s) {

  if (is_stack_empty(s)) {
    printf("Stack Underflow!! Stack empty");
  }

  Node *temp = s->top;
  s->top = s->top->next;

  return temp->data;
  free(temp);
}

int peek_stack(Stack *s) { return s->top->data; }

void show_stack(Stack *s) {

    printf("------------------------------------------\n");
    printf("\t\t Stack");
    printf("\n------------------------------------------\n");

  Node *current = s->top;

  if (is_stack_empty(s)) {

    printf("The stack is empty!!");
  }

  int count = 1;

  while (current != NULL) {

    printf("position %d: %d\n", count, current->data);

    current = current->next;
    count++;
  }

  printf("\n%d elements in the stack", count);
}
