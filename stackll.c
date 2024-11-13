#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* next;

}*top =NULL;


int isEmpty() {
    return top == NULL;
}
struct node {
    int data;
    struct node* next;
};


void push(int data){
struct node* newnode =(struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->next=top;
    top = newnode;
    printf("okay");
    
} 
void pop(){
    struct node* temp = top;
    int ppdata = temp->data;
    top = top->next;
    
    
    free(temp);



}
void display() {
    if (isEmpty()) {
        printf("Stack is empty\n");
        return;
    }
    struct node* current = top;
    printf("Stack: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}





int main() {
    int choice, data;

    while (1) {
        printf("\nStack Operations:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &data);
                push(data);
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}