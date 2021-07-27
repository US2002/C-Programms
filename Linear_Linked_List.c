#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

//Traversing
void linkedListTraversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}

//Insertion Cases
// Case 1
struct Node *insertAtFirst(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;

    ptr->next = head;
    return ptr;
}

// Case 2
struct Node *insertAtEnd(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    struct Node *p = head;

    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = ptr;
    ptr->next = NULL;
    return head;
}

// Case 3
struct Node *insertAfterNode(struct Node *head, struct Node *prevNode, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;

    ptr->next = prevNode->next;
    prevNode->next = ptr;

    return head;
}

//Deletion Cases
// Case 1
struct Node *deleteFirst(struct Node *head)
{
    struct Node *ptr = head;
    head = head->next;
    free(ptr);
    return head;
}

// Case 2
struct Node *deleteAtNode(struct Node *head, int index)
{
    struct Node *p = head;
    struct Node *q = head->next;
    for (int i = 0; i < index - 1; i++)
    {
        p = p->next;
        q = q->next;
    }

    p->next = q->next;
    free(q);
    return head;
}

// Case 3
struct Node *deleteAtLast(struct Node *head)
{
    struct Node *p = head;
    struct Node *q = head->next;
    while (q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }

    p->next = NULL;
    free(q);
    return head;
}

int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;
    int op;

    // Allocate memory for nodes in the linked list in Heap
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));

    // Link first and second nodes
    head->data = 7;
    head->next = second;

    // Link second and third nodes
    second->data = 11;
    second->next = third;

    // Link third and fourth nodes
    third->data = 41;
    third->next = fourth;

    // Terminate the list at the third node
    fourth->data = 66;
    fourth->next = NULL;

    while (1)
    {
        printf("\nBy Ujjawal Soni Sap Id:1000014658\n");
        printf("1.Insertion.\n");
        printf("2.Deletion.\n");
        printf("3.Traversal.\n");
        printf("4.Exit.\n");
        printf("Select one of these:-");
        scanf("%d", &op);

        switch (op)
        {
        case 1:
            printf("\nInitial Linked list\n");
            linkedListTraversal(head);
            int i, data, Node;

            printf("\n1.Insert At First\n");
            printf("2.Insert At End\n");
            printf("3.Insert After Node\n");
            printf("Select-");
            scanf("%d", &i);
            printf("Enter the Element you want to insert-\n");
            scanf("%d", &data);
            switch (i)
            {
            case 1:
                head = insertAtFirst(head, data);
                break;
            case 2:
                head = insertAtEnd(head, data);
                break;
            case 3:
                printf("After which Node-\n");
                scanf("%d", &Node);
                head = insertAfterNode(head, third, data);
                break;
            }
            printf("\nTo watch processed List press 3.\n");
            break;
        case 2:
            printf("\nInitial Linked list\n");
            linkedListTraversal(head);
            int q, index;

            printf("\n1.Delete First\n");
            printf("2.Delete At Last\n");
            printf("3.Delete At Node\n");
            printf("Select-");
            scanf("%d", &q);

            switch (q)
            {
            case 1:
                head = deleteFirst(head);
                break;
            case 2:
                head = deleteAtLast(head);
                break;
            case 3:
                printf("At What Node-");
                scanf("%d", &index);
                head = deleteAtNode(head, 2);
                break;
            }
            printf("\nTo watch processed List press 3.\n");
            break;
        case 3:
            printf("\nInitial Linked list\n");
            linkedListTraversal(head);
            printf("\nLinked list after Process\n");
            linkedListTraversal(head);
            break;

        case 4:
            exit(0);
            break;
        }
    }
    return 0;
}
