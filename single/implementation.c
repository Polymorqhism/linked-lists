#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int data;
  struct Node *next;
} Node;


int main() {
  Node *first_node = malloc(sizeof(Node));
  Node *second_node = malloc(sizeof(Node));
  if(!first_node || !second_node) {
    puts("failed to allocate memory for nodes");
    return 1;
  }

  second_node->data = 11;
  second_node->next = NULL;

  first_node->data = 15;
  first_node->next = second_node;
}
