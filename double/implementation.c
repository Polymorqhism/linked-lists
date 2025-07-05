#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int data;
  struct Node *next;
  struct Node *previous;
} Node;

typedef enum Type {
  HEAD,
  MIDDLE,
  TAIL
} Type;

Type get_node_type(Node *node) {
  Type result = MIDDLE;

  if(!node->previous) {
    result = HEAD;
  } else if(!node->next) {
    result = TAIL;
  }

  return result;
}

void delete_node(Node *node) {
  Type node_type = get_node_type(node);

  switch(node_type) {
    case HEAD:
      if(node->next) {
        node->next->previous = NULL;
      }
      break;
    case MIDDLE:
      if(node->next && node->previous) {
        node->next->previous = node->previous;
        node->previous->next = node->next;
      }
      break;
    case TAIL:
      if(node->previous) {
        node->previous->next = NULL;
      }
      break;
  }

  free(node);
}

void delete_list(Node *head) {

  Node *next = NULL;

  while(head != NULL) {
    next = head->next;
    free(head);
    head = next;
  }
}

Node *get_node_number(int number, Node *head) {
  Node *node = head;
  if(head == NULL) { return head; }

  for(int i = 0; i!=number; i++) {
    if(node->next == NULL) { return node; }
    node = node->next;
  }

  return node;
}

void link_nodes(Node *node, Node *previous, Node *next) {
  node->previous = previous;
  node->next = next;

  if(previous) {
    previous->next = node;
  }

  if(next) {
    next->previous = node;
  }

}

Node *create_node(int data) {
  Node *node = malloc(sizeof(Node));
  if(node == NULL) { puts("allocation failed for node creation"); return node; }

  node->next = NULL;
  node->previous = NULL;
  node->data = data;

  return node;
}

void modify_node_data(Node *node, int data) {
  node->data = data;
}
