#include <stdio.h>
#include <stdlib.h>

/* Definition of a singly linked list node */
typedef struct listint_s {
    int n;
    struct listint_s *next;
} listint_t;

int check_cycle(listint_t *list) {
    listint_t *slow = list;
    listint_t *fast = list;

    /* Traverse the linked list using two pointers: slow and fast */
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;           /* Move slow pointer by one step */
        fast = fast->next->next;     /* Move fast pointer by two steps */

        /* If slow and fast pointers meet, there is a cycle */
        if (slow == fast) {
            return 1;   /* Cycle detected */
        }
    }

    return 0;   /* No cycle detected */
}

/* Helper function to create a new node */
listint_t *create_node(int data) {
    listint_t *new_node = malloc(sizeof(listint_t));
    if (new_node == NULL) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }
    new_node->n = data;
    new_node->next = NULL;
    return new_node;
}

/* Helper function to free the linked list */
void free_list(listint_t *list) {
    listint_t *current = list;
    while (current != NULL) {
        listint_t *temp = current;
        current = current->next;
        free(temp);
    }
}

int main(void) {
    listint_t *head = create_node(1);
    head->next = create_node(2);
    head->next->next = create_node(3);
    head->next->next->next = head;  /* Create a cycle */

    int result = check_cycle(head);
    if (result) {
        printf("Cycle detected\n");
    } else {
        printf("No cycle detected\n");
    }

    /* Clean up */
    free_list(head);

    return 0;
}

