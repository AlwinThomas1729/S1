#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL; // Global variable to store the head of the circular linked list

void insertAtBeginning(int value) {
    // Create a new node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    // Set the value of the new node
    newNode->data = value;

    if (head == NULL) {
        newNode->next = newNode; // Point to itself to form a circular list
        head = newNode;
    } else {
        // Find the last node
        struct Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }

        // Insert the new node at the beginning
        newNode->next = head;
        temp->next = newNode;
        head = newNode;
    }
}

void insertAtEnd(int value) {
    // Create a new node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    // Set the value of the new node
    newNode->data = value;

    if (head == NULL) {
        newNode->next = newNode; // Point to itself to form a circular list
        head = newNode;
    } else {
        // Find the last node
        struct Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }

        // Insert the new node at the end
        newNode->next = head;
        temp->next = newNode;
    }
}

void insertAtPosition(int position, int value) {
    // Create a new node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;

    struct Node* temp = head;
    int i = 0;

    // Traverse to the node just before the position to be inserted
    while (i < position - 1) {
        temp = temp->next;
        i++;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}


void deleteAtBeginning()
{
    struct Node* temp = head;
    temp = head;
    if (head == NULL)
    {
      printf ("Linked List Empty, nothing to delete");
      return;
    }
    // if (temp->next == head)
    // {
    //   head = NULL;
    //   return;
    // }
    struct Node* curr = head;
    curr=head;
    printf("\n %d is deleted from linked list!!!", temp->data);
    while (curr->next != head)
        {
            curr = curr->next;
        }
    curr->next=head->next;
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

    // Traverse to the last node
    while (temp->next != head) {
        prev = temp;
        temp = temp->next;
    }

    if (prev == NULL) { // Only one node in the list
        head = NULL;
    } else {
        // Update pointers to remove the last node
        prev->next = head;
    }

    free(temp);
}

void deleteAtPosition(int position) {
    if (head == NULL) {
        printf("Linked list is already empty.\n");
        return;
    }

    if (position == 1) {
        deleteAtBeginning();
        return;
    }

    struct Node* temp = head;
    struct Node* prev = NULL;
    int count = 0;

    //do
    while (count < position-1) {
        prev = temp;
        temp = temp->next;
        count++;
    } //while (count < position-1);

    if (temp == head) {
        printf("Invalid position.\n");
        return;
    }

    prev->next = temp->next;
    free(temp);
}


void displayList()
{
    struct Node* temp = head;
    if(head==NULL)
        printf("\n Linked List Empty");
    else
    {
    temp = head;
    do
    {
        printf("%d->", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("%d ", head->data);
    }
}

int main() {
    // Insert elements at the beginning
    insertAtBeginning(1);
    insertAtBeginning(2);
    insertAtBeginning(3);

    // Display the original list
    printf("\nCircular Linked List: ");
    displayList();

    // Insert node at the end
    insertAtEnd(4);

    // Display the list after insertion at the end
    printf("\nCircular Linked List after insertion at the end: ");
    displayList();

    // Insert node at a specific position
    insertAtPosition(2, 5);

    // Display the list after insertion at a specific position
    printf("\nCircular Linked List after insertion at a specific position: ");
    displayList();

    // Delete node at the beginning
    deleteAtBeginning();

    // Display the list after deletion at the beginning
    printf("\nCircular Linked List after deletion at the beginning: ");
    displayList();

    // Delete node at the end
    deleteAtEnd();

    // Display the list after deletion at the end
    printf("\nCircular Linked List after deletion at the end: ");
    displayList();

    // Delete node at a specific position
    deleteAtPosition(2);

    // Display the list after deletion at a specific position
    printf("\nCircular Linked List after deletion at a specific position: ");
    displayList();

    return 0;
}
