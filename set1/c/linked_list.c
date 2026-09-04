#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char *value;
    struct Node *prev;
    struct Node *next;
    
} Node;

static char *copy_string(const char *str) {
    size_t lenght = strlen(value) + 1;
    char *copy = malloc(lenght);

    if (copy == NULL) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }

    memcpy(copy, value, lenght);
    return copy;
}

Node *insert(Node **head, Node *after, const char *value) {
    Node *node = malloc(sizeof(*node));

    if (node == NULL) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }

    node->value = copy_string(value);
    node->prev = NULL;
    node->next = *head;

    if(*head != NULL) {
        (*head)->prev = node;
    }

    *head = node;

} else {
    node->prev = after;
    node->next = after->next;

    if (after->next != NULL) {
        after->next->prev = node;
    }

    after->next = node;
}

return node;


Node *find(Node *head, const char *value) {
   for  (Node *current = head; current != NULL; current = current->next) {
        if (strcmp(current->value, value) == 0) {
            return current;
        }
    }

    return NULL;
}

void delete(Node **head, Node *node) {
    if (node == NULL) {
        return;
    }

    if (node->prev != NULL) {
        node->prev->next = node->next;
    } else {
        *head = node->next;
    }

    if (node->next != NULL) {
        node->next->prev = node->prev;
    }

    free(node->value);
    free(node);    
}

void free_list(Node **head) {
  Node *current = *head;

  while (current != NULL) {
    Node *next = current->next;
    free(current->value);
    free(current);
    current = next;
  }

  *head = NULL;
}


