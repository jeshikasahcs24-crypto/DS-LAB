#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node* createNode(int data) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertEnd(struct Node **head, int data) {
    struct Node *newNode = createNode(data);

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct Node *temp = *head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}

void display(struct Node *head) {
    struct Node *temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void reverse(struct Node **head) {
    struct Node *prev = NULL, *curr = *head, *next = NULL;

    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    *head = prev;
}

void sortList(struct Node *head) {
    struct Node *i, *j;
    int temp;

    for (i = head; i != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->data > j->data) {
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
}

void concatenate(struct Node **head1, struct Node *head2) {
    if (*head1 == NULL) {
        *head1 = head2;
        return;
    }

    struct Node *temp = *head1;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = head2;
}
int main() {
    struct Node *list1 = NULL;
    struct Node *list2 = NULL;
    int choice, value;

    while (1) {
        printf("\n---- MENU ----\n");
        printf("1. Insert into List1\n");
        printf("2. Insert into List2\n");
        printf("3. Display List1\n");
        printf("4. Display List2\n");
        printf("5. Sort List1\n");
        printf("6. Reverse List1\n");
        printf("7. Concatenate List2 into List1\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                insertEnd(&list1, value);
                break;

            case 2:
                printf("Enter value: ");
                scanf("%d", &value);
                insertEnd(&list2, value);
                break;

            case 3:
                display(list1);
                break;

            case 4:
                display(list2);
                break;

            case 5:
                sortList(list1);
                printf("List1 sorted.\n");
                break;

            case 6:
                reverse(&list1);
                printf("List1 reversed.\n");
                break;

            case 7:
                concatenate(&list1, list2);
                printf("Lists concatenated.\n");
                break;

            case 8:
                return 0;

            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}
