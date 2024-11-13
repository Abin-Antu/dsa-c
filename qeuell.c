#include <stdio.h>
#include <stdlib.h>

// Node structure for the queue
struct node {
    int data;
    struct node* next;
} *front = NULL, *rear = NULL;

// Function to create a new node
struct node* createNode(int data) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}

// Function to add an element to the queue
void enqueue(int value) {
    struct node* newnode = createNode(value);
    
    if (rear == NULL) {
        front = rear = newnode;  // If queue is empty, both front and rear point to the new node
    } else {
        rear->next = newnode;  // Link the new node to the last node
        rear = newnode;        // Update the rear pointer to the new node
    }
    
    printf("The element %d is enqueued successfully\n", value);
}

// Function to remove and return an element from the queue
int dequeue() {
    if (front == NULL) {
        printf("Queue underflow\n");
        return -1;
    }
    
    struct node* temp = front;
    int value = temp->data;
    
    front = front->next;  // Move the front pointer to the next node
    
    if (front == NULL) {  // If the queue is now empty, set rear to NULL
        rear = NULL;
    }
    
    free(temp);  // Free the memory of the dequeued node
    return value;
}

// Function to display all the elements of the queue
void display() {
    if (front == NULL) {
        printf("The queue is empty\n");
        return;
    }
    
    struct node* temp = front;
    printf("Queue elements: ");
    
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    
    printf("\n");
}

// Function to check if the queue is empty
int isEmpty() {
    return front == NULL;
}

int main() {
    int choice, value;
    
    while (1) {
        printf("Enter your choice\n");
        printf("1. Enqueue\t2. Dequeue\t3. Display\t4. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value you want to insert: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                value = dequeue();
                if (value != -1) {
                    printf("The element %d is dequeued\n", value);
                }
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting\n");
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
