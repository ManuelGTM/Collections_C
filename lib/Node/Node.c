#include "Node.h"
#include <stdlib.h>

Node *create_node(int data) {

  Node *new = (Node *)malloc(sizeof(Node));

  new->data = data;
  new->next = NULL;

  return new;
}
CharNode *create_char_node(char *data){

  CharNode *new = (CharNode *)malloc(sizeof(CharNode));

  new->data = data;
  new->next = NULL;

  return new;
}

void free_node(Node *node) { free(node); }
