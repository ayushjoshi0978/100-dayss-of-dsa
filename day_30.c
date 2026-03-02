// Problem: Polynomial Using Linked List - Implement using linked list with dynamic memory allocation.

// Input:
// - First line: integer n (number of terms)
// - Next n lines: two integers (coefficient and exponent)

// Output:
// - Print polynomial in standard form, e.g., 10x^4 + 20x^3 + 30x^2 + 40x + 50
#include <stdio.h>
#include <stdlib.h>

// Node structure for polynomial term
struct Node {
    int coeff;
    int exp;
    struct Node* next;
};

// Function to insert term at end
struct Node* insert(struct Node* head, int c, int e) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->coeff = c;
    newNode->exp = e;
    newNode->next = NULL;

    if (head == NULL)
        return newNode;

    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    return head;
}

// Function to print polynomial
void printPolynomial(struct Node* head) {
    struct Node* temp = head;

    while (temp != NULL) {
        // Printing format
        if (temp->exp == 0)
            printf("%d", temp->coeff);
        else if (temp->exp == 1)
            printf("%dx", temp->coeff);
        else
            printf("%dx^%d", temp->coeff, temp->exp);

        if (temp->next != NULL)
            printf(" + ");

        temp = temp->next;
    }
}

int main() {
    int n, c, e;
    struct Node* head = NULL;

    // Input number of terms
    scanf("%d", &n);

    // Input coefficient and exponent
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &c, &e);
        head = insert(head, c, e);
    }

    // Print polynomial
    printPolynomial(head);

    return 0;
}