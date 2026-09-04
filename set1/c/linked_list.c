#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char *value;
    struct Node *prev;
    struct Node *next;
    
} Node;

static char *copy_string(const char *value) {
    size_t length = strlen(value) + 1;
    char *copy = malloc(length);

    if (copy == NULL) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }

    memcpy(copy, value, length);
    return copy;
}

Node *insert(Node **head, Node *after, const char *value) {
    Node *node = malloc(sizeof(*node));

    if (node == NULL) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }

    node->value = copy_string(value);
    if (after == NULL) {
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

}


Node *find(Node *head, const char *value) {
   for  (Node *current = head; current != NULL; current = current->next) {
        if (strcmp(current->value, value) == 0) {
            return current;
        }
    }

    return NULL;
}

void delete_item(Node **head, Node *node) {
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

static void assert_order(Node *head, const char *expected[], size_t count) {
  Node *current = head;
  Node *previous = NULL;

  for (size_t i = 0; i < count; i++) {
    assert(current != NULL);
    assert(current->prev == previous);
    assert(strcmp(current->value, expected[i]) == 0);
    previous = current;
    current = current->next;
  }

  assert(current == NULL);
}

int main(void) {
  Node *head = NULL;

  puts("Hello, world!");

  Node *two = insert(&head, NULL, "two");
  Node *one = insert(&head, NULL, "one");
  Node *three = insert(&head, two, "three");

  const char *initial[] = {"one", "two", "three"};
  assert_order(head, initial, 3);
  assert(find(head, "two") == two);
  assert(find(head, "missing") == NULL);

  delete_item(&head, two);
  const char *without_middle[] = {"one", "three"};
  assert_order(head, without_middle, 2);

  delete_item(&head, one);
  const char *without_head[] = {"three"};
  assert_order(head, without_head, 1);

  delete_item(&head, three);
  assert(head == NULL);

  insert(&head, NULL, "temporary");
  free_list(&head);
  assert(head == NULL);

  puts("All doubly linked list tests passed.");
  return 0;
}