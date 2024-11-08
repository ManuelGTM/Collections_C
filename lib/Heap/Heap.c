#include <stdio.h>
#include <stdlib.h>

typedef struct Node {

  int data;
  struct Node *left;
  struct Node *right;

} Node;

Node *new_node(int data) {

  Node *new = (Node *)malloc(sizeof(Node));

  new->data = data;
  new->left = new->right = NULL;

  return new;
}

Node *insert(Node *root, int data) {

  if (root == NULL) {
    root = new_node(data);
  }

  if (data <= root->data) {
    root->left = insert(root->left, data);
  } else {
    root->right = insert(root->right, data);
  }

  return root;
}

// Function to convert the subtree in a heap

void maxHeapify(Node *root, Node *parent) {

  if (root == NULL) {
    return;
  }

  struct Node *largest = parent;

  // Check if the left side have the largest number
  if (parent->left != NULL && parent->left->data > largest->data)

    largest = parent->left;

  // Check if the right side have the largest number
  if (parent->right != NULL && parent->right->data > largest->data)
    largest = parent->right;

  if (largest != parent) {

    // Swapping the value of the root node to child node

    int temp = parent->data;
    parent->data = largest->data;
    largest->data = temp;

    maxHeapify(root, largest);
  }
}

Node *buildHeap(int *arr, int n) {

  Node *root = NULL;

  for (int i = 0; i < n; i++) {
    root = insert(root, arr[i]);
  }
  for (int i = n / 2 - 1; i >= 0; i--) {
    maxHeapify(root, &root[i]);
  }
  return root;

  return root;
}

Node *extract_max(Node *root) {

  if (root == NULL)
    return NULL;

  if (root->left == NULL && root->right == NULL) {
    free(root);
    return NULL;
  }

  if (root->right != NULL) {
    root->right = extract_max(root->right);
  } else {
    Node *temp = root->left;
    free(root);
    return temp;
  }

  return root;
}

void heapSort(int *arr, int n) {

  struct Node *root = buildHeap(arr, n);

  for (int i = n - 1; i >= 0; i--) {

    int temp = root->data;
    root->data = arr[i];
    arr[i] = temp;

    root = extract_max(root);
  }
}

void inorder_traversal(Node *root) {
  if (root != NULL) {
    inorder_traversal(root->left);
    printf("%d\n", root->data);
    inorder_traversal(root->right);
  }
}

void print_arr(int *arr, int n) {
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }

  printf("\n");
}

int main(int argc, char *argv[]) {

  int arr[] = {10, 20, 15, 40, 50, 100};
  int n = sizeof(arr) / sizeof(arr[0]);

  printf("Original Array: ");
  print_arr(arr, n);

  printf("Heapified Array: ");
  heapSort(arr, n);

  print_arr(arr, n);

  return 0;
}
