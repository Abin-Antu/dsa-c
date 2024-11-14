#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

// Global variables for head and tail pointers
struct node *head = NULL;
struct node *tail = NULL;

struct node *createNode(int data) {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = new_node;
    return new_node;
}

void MinandMax() {
    if (head == NULL) {
        printf("The list is empty\n");
        return;
    }

    struct node *temp = head;
    int min = temp->data;
    int max = temp->data;

    do {
        if (temp->data < min) {
            min = temp->data;
        }
        if (temp->data > max) {
            max = temp->data;
        }
        temp = temp->next;
    } while (temp != head);

    printf("The maximum is: %d\n", max);
    printf("The minimum is: %d\n", min);
}

int main() {
    int i, n, value;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter the data for node %d: ", i + 1);
        scanf("%d", &value);

        struct node *new_node = createNode(value);

        if (head == NULL) {
            head = new_node;
            tail = new_node;
        } else {
            tail->next = new_node;
            tail = new_node;
        }

        // Closing the circular link
        tail->next = head;
    }

    MinandMax();

    return 0;
}
