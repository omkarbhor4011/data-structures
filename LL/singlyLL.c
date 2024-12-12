#include <stdio.h>
#include <stdlib.h>

// Node Structure for Singly Linked List
struct Node {
    int data;
    struct Node* next;
};

// Insert at the beginning
void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

// Insert at the end
void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    struct Node* temp = *head;
    newNode->data = data;
    newNode->next = NULL;
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Delete from the beginning
void deleteFromBeginning(struct Node** head) {
    if (*head == NULL) return; // Empty list
    struct Node* temp = *head;
    *head = temp->next;
    free(temp);
}

// Delete from the end
void deleteFromEnd(struct Node** head) {
    if (*head == NULL) return; // Empty list
    struct Node* temp = *head;
    if (temp->next == NULL) {// there is only one element and the list becomes emptayy
        free(temp);
        *head = NULL;
        return;
    }
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
}

// Traverse the list
void traverse(struct Node* head) {
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

// Search for a value in the list
void search(struct Node* head, int key) {
    struct Node* temp = head;
    while (temp != NULL) {
        if (temp->data == key) {
            printf("Element %d found in the list.\n", key);
            return;
        }
        temp = temp->next;
    }
    printf("Element %d not found in the list.\n", key);
}

int main() {
    struct Node* head = NULL;

    insertAtBeginning(&head, 10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);
    insertAtBeginning(&head, 5);
    
    traverse(head);
    
    search(head, 20);
    search(head, 40);
    
    deleteFromEnd(&head);
    traverse(head);
    
    deleteFromBeginning(&head);
    traverse(head);
    
    return 0;
}
