/*Problem: Find Intersection Point of Two Linked Lists - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers (first list)
- Third line: integer m
- Fourth line: m space-separated integers (second list)

Output:
- Print value of intersection node or 'No Intersection*/
#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to create new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Insert at end
struct Node* insertEnd(struct Node* head, int data) {
    struct Node* newNode = createNode(data);

    if (head == NULL)
        return newNode;

    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    return head;
}

// Find length of linked list
int getLength(struct Node* head) {
    int count = 0;
    while (head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}

// Function to find intersection point
void findIntersection(struct Node* head1, struct Node* head2) {

    int len1 = getLength(head1);
    int len2 = getLength(head2);

    int diff = abs(len1 - len2);

    struct Node* ptr1 = head1;
    struct Node* ptr2 = head2;

    // Jo list badi hai usko diff steps aage le jao
    if (len1 > len2) {
        for (int i = 0; i < diff; i++)
            ptr1 = ptr1->next;
    } else {
        for (int i = 0; i < diff; i++)
            ptr2 = ptr2->next;
    }

    // Dono ko ek saath move karo
    while (ptr1 != NULL && ptr2 != NULL) {

        // Address same means intersection
        if (ptr1 == ptr2) {
            printf("%d", ptr1->data);
            return;
        }

        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }

    printf("No Intersection");
}

int main() {

    int n, m, x;

    struct Node *head1 = NULL, *head2 = NULL;

    // First list input
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        head1 = insertEnd(head1, x);
    }

    // Second list input
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &x);
        head2 = insertEnd(head2, x);
    }

    // NOTE:
    // Real intersection happens only if nodes are shared.
    // (Input se normally intersection create nahi hota)

    findIntersection(head1, head2);

    return 0;
}