#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure node with char data and a next pointer
struct node {
    char data;
    struct node *next;
} *head = NULL;

// Modify the push function to use a single pointer instead of double pointer
void push( char data) {
    struct node *new_node;
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = head;
    head = new_node;  // Update global head pointer directly
}

void printReverse(struct node *head) {
    struct node *temp = head;
    while (temp != NULL) {
        printf("%c", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    char a[100];
    printf("Enter the string:\n");

    fgets(a, sizeof(a), stdin);
    for (int i = 0; i < strlen(a); i++) {
        push(a[i]);
    }
    printf("Reversed string is: ");
    printReverse(head);
}
