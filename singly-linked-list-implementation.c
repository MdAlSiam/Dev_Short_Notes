#include <stdio.h>
#include <stdlib.h>

/*
    Functionalities:
        Displaying the linked list
        Insertion of a new node at the end of a linked list 
        Insertion of a a new node at the beginning of a linked list
        Insertion of a new node at the middle of a linked list
        Deleting the first node containing a specific value
*/

/*
    A node of a linked list which will contain its data 
    and a pointer containing the address of the next node
*/
struct Node {
    int data;
    struct Node* next;
};

/*
    Displays the linked list elements.

    Parameter:
        head - the head of the linked list
    Returns:
        Nothing
*/
void displayLinkedList(struct Node* head) {
    // Start at the beginning of the linked list
    struct Node* current = head;
    
    // Traverse the linked list until the end is reached
    while (current != NULL) {
        // Print the data of the current node
        printf(current->next == NULL ? "%d\n" : "%d->", current->data);

        // Move to the next node in the linked list
        current = current->next;
    }
}

/*
    Inserts a new node at the beginning of the list
    Parameters:
        head - the head of the linked list
        data - the data of the node to be inserted
    Returns:
        The new head of the updated linked list

*/
struct Node* insertAtBeginning(struct Node* head, int data) {
    // Create a new node and allocate memory for it
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    // Check if memory allocation was successful
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        // Terminate the program in case of an error
        exit(1); 
    }

    // Set the data of the new node to the provided data
    newNode->data = data;
    // Set the new node's next pointer to point to the current head
    newNode->next = head;
    // Update the head to point to the new node
    head = newNode;

    return head;
}

/*
    Finds the middle node of a linked list
    Parameters:
        head - the head of the linked list
    Returns:
        The pointer to the middle node of the linked list

*/
struct Node* getMiddleNode(struct Node* head) {
    // If the list is empty or has only one node, then the middle is head
    if (head == NULL || head->next == NULL) {
        return head;
    }

    // Initialise two pointers namly slow pointer and fast pointer 
    struct Node* slowPtr = head;
    struct Node* fastPtr = head;
    
    // Traverse the list with moving the slow pointer one step and the fast pointer two steps at a time
    while (fastPtr != NULL && fastPtr->next != NULL) {
        slowPtr = slowPtr->next;
        fastPtr = fastPtr->next->next;
    }
    
    // The slow pointer is at the middle node
    return slowPtr;
}

/*
    Inserts a new node at the middle of the list
    Parameters:
        head - the head of the linked list
        data - the data of the node to be inserted at the middle node
    Returns:
        The new head of the updated linked list
*/
struct Node* insertAtMiddle(struct Node* head, int data) {
    // If head is null, then there the new linked list will have the middle node at head
    if (head == NULL) {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

        // Check if memory allocation was successful
        if (newNode == NULL) {
            printf("Memory allocation failed.\n");
            // Terminate the program in case of an error
            exit(1); 
        }

        newNode->data = data;
        newNode->next = NULL;
        return newNode;
    }
    
    // Find out the middle node of the linked list
    struct Node* middleNode = getMiddleNode(head);
    // Create a new node and allocate memory for it
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    
    // Check if memory allocation was successful
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        // Terminate the program in case of an error
        exit(1); 
    }

    // Set the data of the new node to the provided data
    newNode->data = data;
    // Set the new node's next pointer to point to the head of the middle node
    newNode->next = middleNode->next;
    // The next to the middle node will point to new node
    middleNode->next = newNode;
    
    return head;
}

/*
    Inserts a new node at the end of the list
    Parameters:
        head - the head of the linked list
        data - the data of the node to be inserted at the end
    Returns:
        The new head of the updated linked list
*/
struct Node* insertAtEnd(struct Node* head, int data) {
    // Create a new node and allocate memory for it
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    // Check if memory allocation was successful
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        // Terminate the program in case of an error
        exit(1); 
    }

    // Set the data of the new node to the provided data
    newNode->data = data;
    // Since this node will be inserted at the end, its next should be NULL
    newNode->next = NULL;

    // If the linked list is empty, make the new node the head
    if (head == NULL) {
        head = newNode;
    } 
    else {
        // Otherwise, traverse the list to find the last node
        struct Node* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        // Set the next of the last node to the new node
        current->next = newNode;
    }

    return head;
}

/*
    Deletes the first node containing a specific value from the linked list.
    
    Parameters:
        head - the head of the linked list
        value - the value to be deleted
    Returns:
        The new head of the updated linked list
*/
struct Node* deleteNode(struct Node* head, int value) {
    struct Node* current = head;
    struct Node* prev = NULL;

    while (current != NULL) {
        if (current->data == value) {
            if (prev == NULL) {
                // The value to delete is in the head node
                head = current->next;
            } else {
                prev->next = current->next;
            }
            free(current);
            break; // Stop after deleting the first occurrence
        }
        prev = current;
        current = current->next;
    }

    return head;
}

int main() {
    struct Node* head = NULL; // Initialize an empty linked list
    
    // Insert nodes at the beginning
    head = insertAtBeginning(head, 10);
    head = insertAtBeginning(head, 20);
    head = insertAtBeginning(head, 30);

    // Insert nodes at the end
    head = insertAtEnd(head, 40);
    head = insertAtEnd(head, 50);

    // Insert nodes at the middle
    head = insertAtMiddle(head, 25);

    // Display the linked list
    printf("Linked List: ");
    displayLinkedList(head);

    // Delete the first node containing a specific value (e.g., 30)
    int valueToDelete = 30;
    head = deleteNode(head, valueToDelete);

    // Display the updated linked list
    printf("Linked List after deleting %d: ", valueToDelete);
    displayLinkedList(head);

    // Free memory by deallocating the linked list
    struct Node* current = head;
    while (current != NULL) {
        struct Node* temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}