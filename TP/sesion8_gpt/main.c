#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define a structure for a node in the linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to generate a random number between a and b
int getRandomNumber(int a, int b) {
    return rand() % (b - a + 1) + a;
}

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the end of the linked list
void insertAtEnd(struct Node** headRef, int data) {
    struct Node* newNode = createNode(data);
    if (*headRef == NULL) {
        *headRef = newNode;
        return;
    }
    struct Node* temp = *headRef;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to generate a linked list of n random numbers between a and b
struct Node* generateRandomList(int n, int a, int b) {
    struct Node* head = NULL;
    for (int i = 0; i < n; i++) {
        int randomNumber = getRandomNumber(a, b);
        insertAtEnd(&head, randomNumber);
    }
    return head;
}

// Function to create a new list with copies of the elements from the two argument lists
struct Node* concatenateLists(struct Node* list1, struct Node* list2) {
    struct Node* result = NULL;
    struct Node* temp1 = list1;
    struct Node* temp2 = list2;

    // Copy elements from list1
    while (temp1 != NULL) {
        insertAtEnd(&result, temp1->data);
        temp1 = temp1->next;
    }

    // Copy elements from list2
    while (temp2 != NULL) {
        insertAtEnd(&result, temp2->data);
        temp2 = temp2->next;
    }

    return result;
}

// Function to remove duplicates from the list
void removeDuplicates(struct Node* head) {
    struct Node *current = head, *index, *temp;

    // Base case
    if (head == NULL)
        return;

    // Pick elements one by one
    while (current != NULL && current->next != NULL) {
        index = current;

        // Compare the picked element with the rest of the elements
        while (index->next != NULL) {
            // If duplicate, then delete it
            if (current->data == index->next->data) {
                // Save the next pointer of the node to be deleted
                temp = index->next;
                // Adjust the next pointer of the previous node
                index->next = index->next->next;
                // Free the memory of the node to be deleted
                free(temp);
            } else {
                index = index->next;
            }
        }
        current = current->next;
    }
}

// Function to free the memory of a linked list
void freeList(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

// Function to print the linked list
void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int n1, a1, b1, n2, a2, b2;

    // Seed the random number generator
    srand(time(NULL));

    printf("Enter the size and range for the first list (n1, a1, b1): ");
    scanf("%d %d %d", &n1, &a1, &b1);
    printf("Enter the size and range for the second list (n2, a2, b2): ");
    scanf("%d %d %d", &n2, &a2, &b2);

    // Generate the first linked list
    struct Node* list1 = generateRandomList(n1, a1, b1);
    printf("First List: ");
    printList(list1);

    // Generate the second linked list
    struct Node* list2 = generateRandomList(n2, a2, b2);
    printf("Second List: ");
    printList(list2);

    // Concatenate the two lists
    struct Node* concatenatedList = concatenateLists(list1, list2);
    printf("Concatenated List: ");
    printList(concatenatedList);

    // Remove duplicates from the concatenated list
    removeDuplicates(concatenatedList);
    printf("Concatenated List with Duplicates Removed: ");
    printList(concatenatedList);

    // Free the memory of the lists
    freeList(list1);
    freeList(list2);
    freeList(concatenatedList);

    return 0;
}

