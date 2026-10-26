#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;

// Create a new node
struct node* createNode(int data)
{
    struct node *newNode = (struct node*)malloc(sizeof(struct node));

    newNode->data = data;
    newNode->next = NULL;

    return newNode;
}

// Create Circular Linked List
void createList(int data)
{
    if(head != NULL)
    {
        printf("List already exists.\n");
        return;
    }

    head = createNode(data);
    head->next = head;
}

// Insert at Beginning
void insertAtBeginning(int data)
{
    struct node *newNode = createNode(data);

    if(head == NULL)
    {
        head = newNode;
        head->next = head;
    }
    else
    {
        struct node *temp = head;

        while(temp->next != head)
            temp = temp->next;

        newNode->next = head;
        temp->next = newNode;
        head = newNode;
    }
}

// Insert at End
void insertAtEnd(int data)
{
    struct node *newNode = createNode(data);

    if(head == NULL)
    {
        head = newNode;
        head->next = head;
    }
    else
    {
        struct node *temp = head;

        while(temp->next != head)
            temp = temp->next;

        temp->next = newNode;
        newNode->next = head;
    }
}

// Insert at Position
void insertAtPosition(int data, int position)
{
    if(position < 1)
    {
        printf("Invalid Position\n");
        return;
    }

    if(position == 1)
    {
        insertAtBeginning(data);
        return;
    }

    struct node *temp = head;
    int count = 1;

    while(count < position - 1 && temp->next != head)
    {
        temp = temp->next;
        count++;
    }

    if(count == position - 1)
    {
        struct node *newNode = createNode(data);
        newNode->next = temp->next;
        temp->next = newNode;
    }
    else
    {
        printf("Invalid Position\n");
    }
}

// Delete at Beginning
void deleteAtBeginning()
{
    if(head == NULL)
    {
        printf("List is Empty\n");
        return;
    }

    if(head->next == head)
    {
        free(head);
        head = NULL;
    }
    else
    {
        struct node *last = head;

        while(last->next != head)
            last = last->next;

        struct node *temp = head;
        head = head->next;
        last->next = head;

        free(temp);
    }
}

// Delete at End
void deleteAtEnd()
{
    if(head == NULL)
    {
        printf("List is Empty\n");
        return;
    }

    if(head->next == head)
    {
        free(head);
        head = NULL;
    }
    else
    {
        struct node *temp = head;

        while(temp->next->next != head)
            temp = temp->next;

        free(temp->next);
        temp->next = head;
    }
}

// Delete at Position
void deleteAtPosition(int position)
{
    if(head == NULL)
    {
        printf("List is Empty\n");
        return;
    }

    if(position < 1)
    {
        printf("Invalid Position\n");
        return;
    }

    if(position == 1)
    {
        deleteAtBeginning();
        return;
    }

    struct node *temp = head;
    int count = 1;

    while(count < position - 1 && temp->next != head)
    {
        temp = temp->next;
        count++;
    }

    if(temp->next == head)
    {
        printf("Invalid Position\n");
        return;
    }

    struct node *del = temp->next;
    temp->next = del->next;
    free(del);
}

// Display
void display()
{
    if(head == NULL)
    {
        printf("List is Empty\n");
        return;
    }

    struct node *temp = head;

    printf("Circular Linked List: ");

    do
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    while(temp != head);

    printf("\n");
}

// Main Function
int main()
{
    int choice, data, position;

    while(1)
    {
        printf("\n===== Circular Linked List =====\n");
        printf("1. Create List\n");
        printf("2. Insert at Beginning\n");
        printf("3. Insert at End\n");
        printf("4. Insert at Position\n");
        printf("5. Delete at Beginning\n");
        printf("6. Delete at End\n");
        printf("7. Delete at Position\n");
        printf("8. Display\n");
        printf("9. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("Enter first node data: ");
                scanf("%d", &data);
                createList(data);
                break;

            case 2:
                printf("Enter data: ");
                scanf("%d", &data);
                insertAtBeginning(data);
                break;

            case 3:
                printf("Enter data: ");
                scanf("%d", &data);
                insertAtEnd(data);
                break;

            case 4:
                printf("Enter data: ");
                scanf("%d", &data);

                printf("Enter position: ");
                scanf("%d", &position);

                insertAtPosition(data, position);
                break;

            case 5:
                deleteAtBeginning();
                break;

            case 6:
                deleteAtEnd();
                break;

            case 7:
                printf("Enter position: ");
                scanf("%d", &position);

                deleteAtPosition(position);
                break;

            case 8:
                display();
                break;

            case 9:
                exit(0);

            default:
                printf("Invalid Choice\n");
        }
    }

    return 0;
}
