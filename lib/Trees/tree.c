#include <stdlib.h>
#include "tree.h"
#include <stdio.h>

TreeNode *create_node(int data){

TreeNode *new = (TreeNode *)malloc(sizeof(TreeNode));

new->data = data;
new->right = new->left = NULL;
return new;

}

TreeNode* insert_node(TreeNode *root, int data){
    
    if(root == NULL){ // Base Case to check if there exists root 
        return create_node(data);
    }

    // Sorting the nodes in their respective place

    if (data < root->data){ // if child data is lesser than root 
        root->left = insert_node(root->left, data); // put it in the left
    } else if(data > root ->data){ // if child data is greater than root
        root->right = insert_node(root->right, data); // put it in the right
    }

    return root;
}

TreeNode* search_node(TreeNode *root, int data){
    
    if (root == NULL || root->data == data){
        return root;
    }

    if(data > root->data){
        return search_node(root->right, data);
    }
    
    return search_node(root->left, data);
}


void delete_node(TreeNode *root);

void preorder_traverse(TreeNode *t);
void inorder_traverse(TreeNode *t);
void posorder_traverse(TreeNode *t);
void print_tree(TreeNode *t);
