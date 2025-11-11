#include <stdio.h>
#define MAX 5

int cq[MAX];
int front = -1, rear = -1;

void insert() {
    int value;
    if((rear + 1) % MAX == front) {
        printf("Queue Overflow! Cannot insert more elements.\n");
        return;
    }

    printf("Enter value to insert: ");
    scanf("%d", &value);

    if(front == -1)  
        front = rear = 0;
    else
        rear = (rear + 1) % MAX;

    cq[rear] = value;
    printf("%d inserted into the circular queue.\n", value);
}

void delete() {
    if(front == -1) { 
        printf("Queue Underflow! No elements to delete.\n");
        return;
    }

    printf("%d deleted from the circular queue.\n", cq[front]);

    if(front == rear) 
        front = rear = -1;
    else
        front = (front + 1) % MAX;
}

void display() {
    int i;
    if(front == -1) {
        printf("Circular Queue is empty.\n");
        return;
    }

    printf("Circular Queue elements are:\n");
    i = front;
    while(1) {
        printf("%d ", cq[i]);
        if(i == rear)
            break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main() {
    int choice;

    while(1) {
        printf("\n--- Circular Queue Menu ---\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: insert();
                    break;
            case 2: delete();
                    break;
            case 3: display();
                    break;
            case 4: return 0;
            default: printf("Invalid choice! Try again.\n");
        }
    }
}
