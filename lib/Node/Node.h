#ifndef NODE_H
#define NODE_H

typedef struct Node {
  int data;
  struct Node *next;
} Node;

typedef struct CharNode {
  char *data;
  struct CharNode *next;

} CharNode;

Node *create_node(int data);
CharNode *create_char_node(char *data);
void freeNode(Node *node);

#endif // ! NODE_H
