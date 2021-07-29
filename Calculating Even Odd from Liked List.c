#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct node *create_list(struct node *start);
void display(struct node *start);
struct node *addatbeg(struct node *start, int data);
struct node *addatend(struct node *start, int data);
void EvenOdd(struct node *start1, struct node **start2, struct node **start3);

void main()
{
    int op;
    struct node *start1 = NULL, *start2 = NULL, *start3 = NULL;

    while (1)
    {
        printf("\nBy Ujjawal Soni Sap Id:1000014658\n");
        printf("1.Create.\n");
        printf("2.Even & Odd.\n");
        printf("3.Exit.\n");

        printf("Enter Your Choice.\n");
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            start1 = create_list(start1);
            break;

        case 2:
            EvenOdd(start1, &start2, &start3);
            break;

        case 3:
            exit(0);
        }
    }
}

struct node *create_list(struct node *start)
{
    int i, n, data;
    printf("Enter the number of nodes : ");
    scanf("%d", &n);
    start = NULL;
    if (n == 0)
        return start;

    printf("\nEnter the element to be inserted : ");
    scanf("%d", &data);
    start = addatbeg(start, data);

    for (i = 2; i <= n; i++)
    {
        printf("\nEnter the element to be inserted : ");
        scanf("%d", &data);
        start = addatend(start, data);
    }
    return start;
}

void EvenOdd(struct node *start1, struct node **start2, struct node **start3)
{
    struct node *p1 = start1, *p2 = *start2, *p3 = *start3;

    while (p1 != NULL)
    {
        if (p1->data % 2 != 0)
        {
            if (*start2 == NULL)
                *start2 = addatbeg(*start2, p1->data);
            else
                *start2 = addatend(*start2, p1->data);
        }
        else
        {
            if (*start3 == NULL)
                *start3 = addatbeg(*start3, p1->data);
            else
                *start3 = addatend(*start3, p1->data);
        }
        p1 = p1->next;
    }
    printf("\nOriginal List L1 is :\n");
    display(start1);
    printf("Odd Numbers List L2 is :\n");
    display(start2);
    printf("Even Numbers List L3 is :\n");
    display(start3);
}

struct node *addatbeg(struct node *start, int data)
{
    struct node *tmp;
    tmp = (struct node *)malloc(sizeof(struct node));
    tmp->data = data;
    tmp->next = start;
    start = tmp;
    return start;
} //End of addatbeg()

struct node *addatend(struct node *start, int data)
{
    struct node *p, *tmp;
    tmp = (struct node *)malloc(sizeof(struct node));
    tmp->data = data;
    p = start;
    while (p->next != NULL)
        p = p->next;
    p->next = tmp;
    tmp->next = NULL;
    return start;
}

void display(struct node *start)
{
    struct node *p;
    if (start == NULL)
    {
        printf("Empty\n");
        return;
    }
    p = start;

    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n\n");
}
