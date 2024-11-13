#include<stdio.h>
struct node
{
    int data;
    struct Node* next;
};

// Global head pointer
struct Node* head = NULL;

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the beginning
void insertAtBeginning(int data) {
    struct Node* newNode = createNode(data);
    newNode->next = head;
    head = newNode;
}

// Function to insert a node at the end
void insertAtEnd(int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL) {
        head = newNode;
        return;
    }
    struct Node* last = head;
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = newNode;
}

// Function to insert a node at the n-th position
void insertAtNthPosition(int data, int position) {
    if (position <= 0) {
        printf("Invalid position!\n");
        return;
    }
    
    struct Node* newNode = createNode(data);
    
    // If inserting at the beginning (position 1)
    if (position == 1) {
        newNode->next = head;
        head = newNode;
        return;
    }

    struct Node* temp = head;
    int count = 1;

    // Traverse to the position before the desired position
    while (temp != NULL && count < position - 1) {
        temp = temp->next;
        count++;
    }

    // If position is greater than the number of nodes
    if (temp == NULL) {
        printf("Position exceeds the length of the list!\n");
        free(newNode);
        return;
    }

    // Insert the node at the desired position
    newNode->next = temp->next;
    temp->next = newNode;
}

// Function to delete a node from the front (beginning)
void deleteFromFront() {
    if (head == NULL) {
        printf("List is empty, nothing to delete.\n");
        return;
    }
    struct Node* temp = head;
    head = head->next; // Move the head to the next node
    free(temp); // Free the memory of the old head
    printf("Node deleted from the front.\n");
}

// Function to delete a node from the end
void deleteFromEnd() {
    if (head == NULL) {
        printf("List is empty, nothing to delete.\n");
        return;
    }

    // If there is only one node
    if (head->next == NULL) {
        free(head);
        head = NULL;
        printf("Node deleted from the end.\n");
        return;
    }

    struct Node* temp = head;
    while (temp->next != NULL && temp->next->next != NULL) {
        temp = temp->next; // Traverse to the second last node
    }

    // Delete the last node
    struct Node* last = temp->next;
    temp->next = NULL;
    free(last);
    printf("Node deleted from the end.\n");
}

// Function to display the linked list
void display() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int choice, value, position;

    while (1) {
        printf("\nOperations Menu:\n");
        printf("1. Insert at the beginning\n");
        printf("2. Insert at the end\n");
        printf("3. Insert at the n-th position\n");
        printf("4. Delete from the front\n");
        printf("5. Delete from the end\n");
        printf("6. Display the list\n");
        printf("7. Exit\n");

        printf("Enter your choice (1-7): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to insert at the beginning: ");
                scanf("%d", &value);
                insertAtBeginning(value);
                break;
            case 2:
                printf("Enter the value to insert at the end: ");
                scanf("%d", &value);
                insertAtEnd(value);
                break;
            case 3:
                printf("Enter the value to insert and the position: ");
                scanf("%d %d", &value, &position);
                insertAtNthPosition(value, position);
                break;
            case 4:
                deleteFromFront();
                break;
            case 5:
                deleteFromEnd();
                break;
            case 6:
                printf("Linked List: ");
                display();
                break;
            case 7:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
