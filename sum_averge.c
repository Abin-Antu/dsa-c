#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

// Global variable for head pointer
struct node *head = NULL;

struct node *createNode(int data) {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

void calculateSumAndAverage() {
    struct node *temp = head;
    int sum = 0, count = 0;

    while (temp != NULL) {
        sum += temp->data;
        count++;
        temp = temp->next;
    }

    if (count > 0) {
        float average = (float)sum / count;
        printf("Sum: %d\n", sum);
        printf("Average: %.2f\n", average);
    } else {
        printf("The list is empty\n");
    }
}

int main() {
    int i, n, value;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter the data for node %d: ", i + 1);
        scanf("%d", &value);

        struct node *new_node = createNode(value);
        new_node->next = head;
        head = new_node;
    }

    calculateSumAndAverage();

    return 0;
}
