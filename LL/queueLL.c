#include <stdio.h>
#include <stdlib.h>

// Define a Node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to check if the queue is empty
int isEmpty(struct Node* front) {
    return front == NULL;
}

// Enqueue (insert) an element at the rear of the queue
void enqueue(struct Node** front, struct Node** rear, int value) {
    // Allocate memory for the new node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    newNode->data = value;
    newNode->next = NULL;

    // If the queue is empty, both front and rear will point to the new node
    if (*rear == NULL) { // initialization: front -> value <- rear
        *front = *rear = newNode;
    } else {
        // Otherwise, add the new node at the end and update rear
        (*rear)->next = newNode;
        *rear = newNode;
    }
}

// Dequeue (remove) an element from the front of the queue
int dequeue(struct Node** front, struct Node** rear) {
    if (isEmpty(*front)) {
        printf("Queue is empty!\n");
        return -1;
    }

    struct Node* temp = *front;
    int dequeuedValue = (*front)->data;
    *front = (*front)->next;

    // If the queue becomes empty, set rear to NULL
    if (*front == NULL) {
        *rear = NULL;
    }

    // Free the memory of the dequeued node
    free(temp);
    return dequeuedValue;
}

// Peek the front element of the queue
int peek(struct Node* front) {
    if (isEmpty(front)) {
        printf("Queue is empty!\n");
        return -1;
    }
    return front->data;
}

// Display the elements of the queue
void display(struct Node* front) {
    if (isEmpty(front)) {
        printf("Queue is empty!\n");
        return;
    }

    struct Node* temp = front;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct Node* front = NULL;
    struct Node* rear = NULL;

    // Test enqueue
    enqueue(&front, &rear, 10);
    enqueue(&front, &rear, 20);
    enqueue(&front, &rear, 30);

    // Display the queue
    printf("Queue: ");
    display(front);

    // Test peek
    printf("Front element: %d\n", peek(front));

    // Test dequeue
    printf("Dequeued: %d\n", dequeue(&front, &rear));

    // Display queue after dequeue
    printf("Queue after dequeue: ");
    display(front);

    return 0;
}
