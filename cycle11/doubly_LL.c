#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Node* head = NULL; // Global variable to store the head of the doubly linked list

void insertAtBeginning(int value) {
    // Create a new node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    // Set the value of the new node
    newNode->data = value;

    // Update pointers for the new node
    newNode->prev = NULL;
    newNode->next = head;

    if (head != NULL) {
        head->prev = newNode;
    }

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
        newNode->prev = NULL;
        head = newNode;
        return;
    }

    // Traverse to the end of the list
    while (temp->next != NULL) {
        temp = temp->next;
    }

    // Update pointers for the new node
    temp->next = newNode;
    newNode->prev = temp;
}

void insertAtPosition(int position, int value) {
    // Create a new node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    struct Node* temp = head;
    int count = 1;

    // Set the value of the new node
    newNode->data = value;

    // Handle insertion at the beginning separately
    if (position == 1 || head == NULL) {
        newNode->next = head;
        newNode->prev = NULL;
        if (head != NULL) {
            head->prev = newNode;
        }
        head = newNode;
        return;
    }

    // Traverse to the specified position or to the end of the list
    while (temp != NULL && count < position) {
        temp = temp->next;
        count++;
    }

    if (temp == NULL) {
        printf("Invalid position.\n");
        return;
    }

    // Update pointers for the new node
    newNode->next = temp;
    newNode->prev = temp->prev;
    temp->prev->next = newNode;
    temp->prev = newNode;
}

void deleteAtBeginning() {
    if (head == NULL) {
        printf("Linked list is already empty.\n");
        return;
    }

    struct Node* temp = head;
    head = head->next;

    if (head != NULL) {
        head->prev = NULL;
    }

    free(temp);
}

void deleteAtEnd() {
    if (head == NULL) {
        printf("Linked list is already empty.\n");
        return;
    }

    struct Node* temp = head;

    while (temp->next != NULL) {
        temp = temp->next;
    }

    if (temp->prev != NULL) {
        temp->prev->next = NULL;
    } else {
        head = NULL;
    }

    free(temp);
}

void deleteAtPosition(int position) {
    if (head == NULL) {
        printf("Linked list is already empty.\n");
        return;
    }

    struct Node* temp = head;
    int count = 1;

    if (position == 1) {
        head = temp->next;
        if (head != NULL) {
            head->prev = NULL;
        }
        free(temp);
        return;
    }

    // Traverse to the specified position or to the end of the list
    while (temp != NULL && count < position) {
        temp = temp->next;
        count++;
    }

    if (temp == NULL) {
        printf("Invalid position.\n");
        return;
    }

    // Update pointers to remove the node at the specified position
    temp->prev->next = temp->next;
    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }

    free(temp);
}

void displayList() {
    struct Node* temp = head;

    // Traverse and print the list forward
    printf("Forward: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");

    // Traverse and print the list backward
    printf("Backward: ");
    temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("\n");
}

int main() {
    // Insert elements at the beginning
    insertAtBeginning(1);
    insertAtBeginning(2);
    insertAtBeginning(3);

    // Display the original list
    displayList();

    // Insert node at the end
    insertAtEnd(4);

    // Display the list after insertion at the end
    displayList();

    // Insert node at a specific position
    insertAtPosition(2, 5);

    // Display the list after insertion at a specific position
    displayList();

    // Delete node at the beginning
    deleteAtBeginning();

    // Display the list after deletion at the beginning
    displayList();

    // Delete node at the end
    deleteAtEnd();

    // Display the list after deletion at the end
    displayList();

    // Delete node at a specific position
    deleteAtPosition(2);

    // Display the list after deletion at a specific position
    displayList();

    return 0;
}
