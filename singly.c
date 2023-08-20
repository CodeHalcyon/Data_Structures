#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
} *head, *temp;

void insertBegin(int data)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    if (head == NULL)
        head = newnode;
    else
    {
        newnode->next = head;
        head = newnode;
    }
}

void insertLast(int data)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    if (head == NULL)
        head = newnode;
    else
    {
        temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
    }
}

void insertAtPos(int data, int pos)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    temp = head;
    while (pos - 2)
    {
        temp = temp->next;
        pos--;
    }
    newnode->next = temp->next;
    temp->next = newnode;
}

void deleteBeg()
{
    struct node *delnode;
    temp = head;
    if (head == NULL)
        printf("nothing to delete");
    else if (head->next == NULL)
    {
        head = NULL;
        delnode = head;
        free(delnode);
    }
    else
    {
        delnode = head;
        head = head->next;
        free(delnode);
    }
}

void deleteEnd()
{
    struct node *delnode;
    temp = head;
    if (head == NULL)
        printf("\n Nothing to delete");

    else if (head->next == NULL)
    {
        delnode = head;
        head = NULL;
        free(delnode);
    }

    else
    {
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        delnode = temp->next;
        temp->next = NULL;
        free(delnode);
    }
}

void deleteAtPos(int pos)
{
    struct node *delnode;
    temp = head;
    while (pos - 2)
    {
        temp = temp->next;
        pos--;
    }
    delnode = temp->next;
    temp->next = temp->next->next;
    free(delnode);
}

void Display()
{
    temp = head;
    printf("\n");
    while (temp != NULL)
    {
        printf("%d->", temp->data);
        temp = temp->next;
    }
}

int main()
{

    int ch, data, pos;
    printf("\n=====MENU====");
    printf("\n1 - Insert at Start");
    printf("\n2 - Insert at End");
    printf("\n3 - Insert at Position");
    printf("\n4 - Delete at Start");
    printf("\n5 - Delete at End");
    printf("\n6 - Delete at Position");
    printf("\n7 - Display the list");
    printf("\n8 - Exit");

    while (1)
    {
        printf("\nEnter your choice");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("\nEnter data: ");
            scanf("%d", &data);
            insertBegin(data);
            break;

        case 2:
            printf("\nEnter data: ");
            scanf("%d", &data);
            insertLast(data);
            break;

        case 3:
            printf("\nEnter position: ");
            scanf("%d", &pos);

            printf("\nEnter data: ");
            scanf("%d", &data);

            insertAtPos(data, pos);
            break;

        case 4:
            deleteBeg();
            break;

        case 5:
            deleteEnd();
            break;

        case 6:
            printf("\nEnter position: ");
            scanf("%d", &pos);

            deleteAtPos(pos);

        case 7:
            Display();

        case 8:
            exit(0);
        default:
            printf("\nInvalid Choice!!");
        }
    }
    return 0;
}
