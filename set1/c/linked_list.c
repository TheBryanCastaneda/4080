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
    Node *current = head;

    while (current != NULL) {
        if (strcmp(current->value, value) == 0) {
            return current;
        }
        current = current->next;
    }

    return NULL;
}

