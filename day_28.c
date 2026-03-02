/*Problem: Circular Linked List Creation and Traversal - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers

Output:
- Print the circular linked list elements starting from head, space-separated*/
#include <stdio.h>  
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

int main() {
    int n, i, value;
    struct Node *head = NULL, *temp = NULL, *newNode = NULL;

    // Input number of nodes
    scanf("%d", &n);

    if (n <= 0) {
        return 0;
    }

    // Create circular linked list
    for (i = 0; i < n; i++) {
        scanf("%d", &value);

        // Allocate memory dynamically
        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = value;
        newNode->next = NULL;

        // First node
        if (head == NULL) {
            head = newNode;
            temp = head;
        }
        else {
            temp->next = newNode;
            temp = newNode;
        }
    }

    // Make list circular
    temp->next = head;

    // Traversal of circular linked list
    struct Node* current = head;

    do {
        printf("%d ", current->data);
        current = current->next;
    } while (current != head);

    return 0;
}