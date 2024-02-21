#include <stdio.h>
#include <stdlib.h>

// Structure for a node
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Function to insert a node in ascending order
void insertInAscendingOrder(struct Node** head, int data) {
    // Create a new node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;

    // If the list is empty, make the new node as the head
    if (*head == NULL) {
        *head = newNode;
        return;
    }

    // If the data of the new node is less than the head, insert it at the beginning
    if (data < (*head)->data) {
        newNode->next = *head;
        (*head)->prev = newNode;
        *head = newNode;
        return;
    }

    // Find the appropriate position to insert the new node
    struct Node* current = *head;
    while (current->next != NULL && current->next->data < data) {
        current = current->next;
    }

    // Insert the new node at the appropriate position
    newNode->next = current->next;
    newNode->prev = current;
    if (current->next != NULL) {
        current->next->prev = newNode;
    }
    current->next = newNode;
}

// Function to remove a node from the list
void removeNode(struct Node** head, struct Node* node) {
    if (*head == NULL || node == NULL) {
        return;
    }

    // If the node to be deleted is the head
    if (*head == node) {
        *head = node->next;
    }

    // Adjust the links of the previous and next nodes
    if (node->prev != NULL) {
        node->prev->next = node->next;
    }
    if (node->next != NULL) {
        node->next->prev = node->prev;
    }

    // Free the memory occupied by the node
    free(node);
}

// Function to search for a node with a given data value
struct Node* searchNode(struct Node* head, int data) {
    struct Node* current = head;
    while (current != NULL) {
        if (current->data == data) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

// Function to display the doubly linked list
void displayList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Main function
int main() {
    struct Node* head = NULL;

    // Insert nodes in ascending order
    insertInAscendingOrder(&head, 5);
    insertInAscendingOrder(&head, 3);
    insertInAscendingOrder(&head, 7);
    insertInAscendingOrder(&head, 1);
    insertInAscendingOrder(&head, 9);

    printf("Doubly linked list: ");
    displayList(head);

    // Remove a node with data value 3
    struct Node* nodeToRemove = searchNode(head, 3);
    removeNode(&head, nodeToRemove);

    printf("After removing a node with data 3: ");
    displayList(head);

    // Search for
}
