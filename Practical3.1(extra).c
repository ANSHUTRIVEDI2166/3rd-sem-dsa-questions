#include <stdio.h>
struct Node {
    int data;
    struct Node* next;
};
struct Node* head = NULL;
void insertAtFront(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = head;
    head = newNode;
    printf("Inserted %d at front:\n", data);
    display();
}
void deleteAtLast() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    if (head->next == NULL) {
        printf("Deleted %d\n", head->data);
        free(head);
        head = NULL;
        return;
    }
    struct Node* secondLast = head;
    while (secondLast->next->next != NULL) {
        secondLast = secondLast->next;
    }
    printf("Deleted %d\n", secondLast->next->data);
    free(secondLast->next);
    secondLast->next = NULL;
    display();
}
void deleteNthFromEnd(int n) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    if (n <= 0) {
        printf("Invalid n\n");
        return;
    }
    if (n == 1) {
        deleteAtLast();
        return;
    }
    struct Node* slow = head;
    struct Node* fast = head;
    for (int i = 0; i < n; i++) {
        if (fast == NULL) {
            printf("n is greater than length of list\n");
            return;
        }
        fast = fast->next;
    }
        while (fast->next != NULL) {
        slow = slow->next;
        fast = fast->next;
    }
    printf("Deleted %d\n", slow->next->data);
    struct Node* temp = slow->next;
    slow->next = slow->next->next;
    free(temp);
    display();
}
void deleteAll() {
    struct Node* current = head;
    while (current != NULL) {
        struct Node* temp = current;
        current = current->next;
        free(temp);
    }
    head = NULL;
    printf("Deleted all nodes\n");
    display();
}
void display() {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}
void menu() {
    int choice;
    do {
        printf("\nLinked List Operations:\n");
        printf("1. Insert at front\n");
        printf("2. Delete at last\n");
        printf("3. Delete Nth Node from End\n");
        printf("4. Delete all nodes\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter data to insert: ");
                int data;
                scanf("%d", &data);
                insertAtFront(data);
                break;
            case 2:
                deleteAtLast();
                break;
            case 3:
                printf("Enter N: ");
                int n;
                scanf("%d", &n);
                deleteNthFromEnd(n);
                break;
            case 4:
                deleteAll();
                break;
            case 5:
                display();
                break;
            case 6:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 6);
}
int main() {
    menu();
    return 0;
}