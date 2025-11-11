#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

void create() {
    int n, value;
    struct node *newnode, *temp;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        printf("Enter data: ");
        scanf("%d", &value);

        newnode = (struct node*)malloc(sizeof(struct node));
        newnode->data = value;
        newnode->next = NULL;

        if(head == NULL) {
            head = newnode;
            temp = newnode;
        } else {
            temp->next = newnode;
            temp = newnode;
        }
    }
}

void insertAtBeginning() {
    int value;
    struct node *newnode;

    printf("Enter data to insert at beginning: ");
    scanf("%d", &value);

    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->next = head;
    head = newnode;
}

void insertAtEnd() {
    int value;
    struct node *newnode, *temp;

    printf("Enter data to insert at end: ");
    scanf("%d", &value);

    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->next = NULL;

    if(head == NULL) {
        head = newnode;
    } else {
        temp = head;
        while(temp->next != NULL)
            temp = temp->next;
        temp->next = newnode;
    }
}

void insertAtPosition() {
    int value, pos, i = 1;
    struct node *newnode, *temp;

    printf("Enter position to insert: ");
    scanf("%d", &pos);
    printf("Enter data: ");
    scanf("%d", &value);

    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->next = NULL;

    if(pos == 1) {
        newnode->next = head;
        head = newnode;
        return;
    }

    temp = head;
    while(i < pos - 1 && temp != NULL) {
        temp = temp->next;
        i++;
    }

    if(temp == NULL) {
        printf("Position out of range.\n");
        free(newnode);
    } else {
        newnode->next = temp->next;
        temp->next = newnode;
    }
}

void display() {
    struct node *temp = head;
    if(head == NULL) {
        printf("List is empty.\n");
        return;
    }

    printf("Linked List: ");
    while(temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int choice;

    while(1) {
        printf("\n--- Singly Linked List Menu ---\n");
        printf("1. Create List\n");
        printf("2. Insert at Beginning\n");
        printf("3. Insert at Position\n");
        printf("4. Insert at End\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: create(); break;
            case 2: insertAtBeginning(); break;
            case 3: insertAtPosition(); break;
            case 4: insertAtEnd(); break;
            case 5: display(); break;
            case 6: return 0;
            default: printf("Invalid choice. Try again.\n");
        }
    }
}
