#include <stdio.h>

#define MAX 2
int queue[MAX], front = -1;
int rear = -1;

void display();
void enq();
void deq();

void main() {
    int act;

    while (1) {  // Infinite loop to continue until user decides to exit
        printf("\nSelect an action:\n");
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &act);

        switch (act) {
            case 1:
                enq();
                break;
            case 2:
                deq();
                break;
            case 3:
                display();
                break;
            case 4:
                return;  // Exit the program
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }
}

void enq() {
    int item;
    printf("Enter the item to enqueue: ");
    scanf("%d", &item);

    if (rear == MAX - 1) {
        printf("Overflow\n");
    } else {
        if (front == -1) {
            front = 0;
        }
        rear++;
        queue[rear] = item;
        printf("Successfully inserted %d\n", item);
    }
}

void deq() {
    int del;
    if (front == -1 || front > rear) {
        printf("Underflow\n");
    } else {
        del = queue[front];
        printf("Successfully deleted %d\n", del);
        front++;
        if (front > rear) {
            front = rear = -1;  // Reset when the queue is empty
        }
    }
}

void display() {
    if (front == -1) {
        printf("Queue is empty\n");
    } else {
        printf("Queue elements are: ");
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}
