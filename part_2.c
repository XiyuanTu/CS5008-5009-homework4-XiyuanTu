#include <stdio.h>
#include <stdlib.h>

// Structure for a node in the priority queue
struct Node {
    int data;
    int priority;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data, int priority) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->priority = priority;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node into the priority queue based on its priority
void Enqueue(struct Node** head, int data, int priority) {
    struct Node* newNode = createNode(data, priority);

    if (*head == NULL || priority < (*head)->priority) {
        newNode->next = *head;
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL && temp->next->priority <= priority) {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }

    printf("Enqueued element %d with priority %d\n", data, priority);
}

// Function to delete the head node (highest priority) from the priority queue
void Dequeue(struct Node** head) {
    if (*head == NULL) {
        printf("Priority queue is empty. Cannot dequeue.\n");
        return;
    }

    struct Node* temp = *head;
    *head = (*head)->next;
    printf("Dequeued element %d with priority %d\n", temp->data, temp->priority);
    free(temp);
}

// Function to check if the priority queue is empty
int isEmpty(struct Node* head) {
    return head == NULL;
}

// Function to check if the priority queue is full (always returns 0 as it is a linked list)
int isFull() {
    return 0;
}

// Function to display the elements of the priority queue
void display(struct Node* head) {
    if (isEmpty(head)) {
        printf("Priority queue is empty.\n");
        return;
    }

    struct Node* temp = head;
    printf("Priority queue: ");
    while (temp != NULL) {
        printf("%d[%d] ", temp->data, temp->priority);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;
    int choice, data, priority;

    do {
        printf("\nPriority Queue Operations:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Check if empty\n");
        printf("4. Check if full\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to enqueue: ");
                scanf("%d", &data);
                printf("Enter the priority: ");
                scanf("%d", &priority);
                Enqueue(&head, data, priority);
                break;
            case 2:
                Dequeue(&head);
                break;
            case 3:
                if (isEmpty(head))
                    printf("Priority queue is empty.\n");
                else
                    printf("Priority queue is not empty.\n");
                break;
            case 4:
                if (isFull())
                    printf("Priority queue is full.\n");
                    else
                        printf("Priority queue is not full.\n");
                break;
            case 5:
                display(head);
                break;
            case 6:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 6);

    // Free the allocated memory
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
