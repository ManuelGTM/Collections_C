#ifndef TREE_H
#define TREE_H

typedef struct TreeNode {

  int data;
  struct TreeNode *left;
  struct TreeNode *right;

} TreeNode;

TreeNode *tree_initialize(int data);
TreeNode *insert_node(TreeNode *root, int data);
TreeNode *search_node(TreeNode *root, int data);
void delete_node(TreeNode *root);

void preorder_traverse(TreeNode *t);
void inorder_traverse(TreeNode *t);
void posorder_traverse(TreeNode *t);
void print_tree(TreeNode *t);

#endif // !TREE_H
