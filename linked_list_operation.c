#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node* createNode(int data) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
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

    insertEnd(&list1, 30);
    insertEnd(&list1, 10);
    insertEnd(&list1, 20);

    printf("List 1: ");
    display(list1);

    sortList(list1);
    printf("Sorted List 1: ");
    display(list1);

    reverse(&list1);
    printf("Reversed List 1: ");
    display(list1);

    insertEnd(&list2, 5);
    insertEnd(&list2, 15);

    printf("List 2: ");
    display(list2);

    concatenate(&list1, list2);
    printf("Concatenated List: ");
    display(list1);

    return 0;
}
