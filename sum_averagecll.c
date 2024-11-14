#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

// Global pointers for head and tail
struct node *head = NULL;
struct node *tail = NULL;

struct node *createNode(int data) {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

void calculateSumAndAverage() {
    if (head == NULL) {
        printf("The list is empty\n");
        return;
    }
    
    struct node *temp = head;
    int sum = 0, count = 0;

    do {
        sum += temp->data;
        count++;
        temp = temp->next;
    } while (temp != head); // Traverse until we come back to the head

    float average = (float)sum / count;
    printf("Sum: %d\n", sum);
    printf("Average: %.2f\n", average);
}

void insertAtEnd(int data) {
    struct node *new_node = createNode(data);
    if (head == NULL) {
        head = new_node;
        tail = new_node;
        new_node->next = head; // Points to itself to form a circular link
    } else {
        tail->next = new_node;
        new_node->next = head;
        tail = new_node;
    }
}

int main() {
    int i, n, value;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter the data for node %d: ", i + 1);
        scanf("%d", &value);
        insertAtEnd(value);
    }

    calculateSumAndAverage();

    return 0;
}
