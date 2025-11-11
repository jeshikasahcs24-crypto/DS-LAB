#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

void create() {
    int n, val;
    struct node *t, *p;
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        printf("Enter data: ");
        scanf("%d", &val);
        t = (struct node*)malloc(sizeof(struct node));
        t->data = val;
        t->next = NULL;

        if(head == NULL)
            head = t;
        else {
            p = head;
            while(p->next != NULL)
                p = p->next;
            p->next = t;
        }
    }
}

void deleteFirst() {
    struct node *t;
    if(head == NULL) {
        printf("List empty\n"); return;
    }
    t = head;
    head = head->next;
    free(t);
}

void deleteValue() {
    int val;
    struct node *p = head, *prev = NULL;
    if(head == NULL) {
        printf("List empty\n"); return;
    }
    printf("Enter value to delete: ");
    scanf("%d", &val);

    while(p != NULL && p->data != val) {
        prev = p;
        p = p->next;
    }
    if(p == NULL) {
        printf("Value not found\n"); return;
    }
    if(prev == NULL)
        head = head->next;
    else
        prev->next = p->next;
    free(p);
}

void deleteLast() {
    struct node *p = head, *prev = NULL;
    if(head == NULL) {
        printf("List empty\n"); return;
    }
    while(p->next != NULL) {
        prev = p;
        p = p->next;
    }
    if(prev == NULL)
        head = NULL;
    else
        prev->next = NULL;
    free(p);
}

void display() {
    struct node *p = head;
    if(head == NULL) {
        printf("List empty\n"); return;
    }
    while(p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int main() {
    int ch;
    while(1) {
        printf("\n1.Create  2.Del First  3.Del Value  4.Del Last  5.Display  6.Exit\n");
        scanf("%d", &ch);
        switch(ch) {
            case 1: create(); break;
            case 2: deleteFirst(); break;
            case 3: deleteValue(); break;
            case 4: deleteLast(); break;
            case 5: display(); break;
            case 6: return 0;
        }
    }
}
