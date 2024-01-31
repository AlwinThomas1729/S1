#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL; // Global variable to store the head of the linked list

void insertAtBeginning(int value) {
    // Create a new node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    // Set the value of the new node
    newNode->data = value;

    // Point the new node to the current head
    newNode->next = head;

    // Update the head to point to the new node
    head = newNode;
}

void insertAtEnd(int value) {
    // Create a new node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    struct Node* temp = head;

    // Set the value of the new node
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        return;
    }

    // Traverse to the end of the list
    while (temp->next != NULL) {
        temp = temp->next;
    }

    // Insert the new node at the end
    temp->next = newNode;
}

void insertAtPosition(int position, int value) {
    // Create a new node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    struct Node* temp = head;
    struct Node* prev = NULL;
    int count = 1;

    // Set the value of the new node
    newNode->data = value;

    // Handle insertion at the beginning separately
    if (position == 1) {
        newNode->next = head;
        head = newNode;
        return;
    }

    // Traverse to the specified position or to the end of the list
    while (temp != NULL && count < position) {
        prev = temp;
        temp = temp->next;
        count++;
    }

    // Insert the new node at the specified position
    prev->next = newNode;
    newNode->next = temp;
}

void deleteAtBeginning() {
    if (head == NULL) {
        printf("Linked list is already empty.\n");
        return;
    }

    struct Node* temp = head;
    head = head->next;
    free(temp);
}

void deleteAtEnd() {
    if (head == NULL) {
        printf("Linked list is already empty.\n");
        return;
    }

    struct Node* temp = head;
    struct Node* prev = NULL;

    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }

    if (prev == NULL) {
        head = NULL;
    } else {
        prev->next = NULL;
    }

    free(temp);
}

void deleteAtPosition(int position) {
    if (head == NULL) {
        printf("Linked list is already empty.\n");
        return;
    }

    struct Node* temp = head;
    struct Node* prev = NULL;
    int count = 1;

    if (position == 1) {
        head = temp->next;
        free(temp);
        return;
    }

    for (int i = 1; temp != NULL && i < position; i++) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Invalid position.\n");
        return;
    }

    prev->next = temp->next;
    free(temp);
}

void displayList() {
    struct Node* temp = head;

    // Traverse and print the list
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    // Insert elements at the beginning
    insertAtBeginning(1);
    insertAtBeginning(2);
    insertAtBeginning(3);

    // Display the original list
    printf("Linked List: ");
    displayList();

    // Insert node at the end
    insertAtEnd(4);

    // Display the list after insertion at the end
    printf("Linked List after insertion at the end: ");
    displayList();

    // Insert node at a specific position
    insertAtPosition(2, 5);

    // Display the list after insertion at a specific position
    printf("Linked List after insertion at a specific position: ");
    displayList();

    // Delete node at the beginning
    deleteAtBeginning();

    // Display the list after deletion at the beginning
    printf("Linked List after deletion at the beginning: ");
    displayList();

    // Delete node at the end
    deleteAtEnd();

    // Display the list after deletion at the end
    printf("Linked List after deletion at the end: ");
    displayList();

    // Delete node at a specific position
    deleteAtPosition(2);

    // Display the list after deletion at a specific position
    printf("Linked List after deletion at a specific position: ");
    displayList();

    return 0;
}
