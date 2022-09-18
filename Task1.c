
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
    struct node *prev;
};
struct node *deleteFromBeg(struct node *head, int position)
{
    struct node *temporary;
    if (head == NULL)
    {
        printf("The Double Linked List is empty\n");
    }
    else
    {
        temporary = head;
        head = temporary->next;
        head->prev = NULL;
        free(temporary);
    }
    return head;
}
struct node *deleteFromAnyPos(struct node *head, int position)
{
    struct node *temporary;
    if (head == NULL)
    {
        printf("The Double Linked List is empty\n");
    }
    else
    {
        int i = 1;
        temporary = head;
        while (i < position)
        {
            temporary = temporary->next;
            i++;
        }
        temporary->next->prev = temporary->prev;
        temporary->prev->next = temporary->next;
        free(temporary);
    }
    return head;
}

struct node *deleteFromEnd(struct node *head, int position)
{
    struct node *temporary;
    if (head == NULL)
    {
        printf("The Double Linked List is empty\n");
    }
    else
    {
        int i = 1;
        temporary = head;
        while (temporary->next != NULL)
        {
            temporary = temporary->next;
        }

        temporary->prev->next = NULL;
        free(temporary);
    }
    return head;
}

int main()
{
    int n;
    printf("Enter the Number of elements in the double linked list :\n");
    scanf("%d", &n);
    struct node *head = NULL, *temporary;
    for (int i = 0; i < n; i++)
    {
        struct node *newnode;
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter the data of %d element\n", i + 1);
        scanf("%d", &newnode->data);
        if (head == NULL)
        {
            head = newnode;
            temporary = head;

            newnode->prev = NULL;
        }
        else
        {
            temporary->next = newnode;
            newnode->prev = temporary;
            temporary = newnode;
        }
        temporary->next = NULL;
    }
    printf("Before deletion our Double Linked List Looks Like this :\n");
    temporary = head;
    // printf("After Deletion our Linked List Looks like :\n");
    while (temporary != NULL)
    {
        printf("%d\n", temporary->data);
        temporary = temporary->next;
    }
    int position, integer, ind = 0;
    printf("\nEnter The integer that you want to delete from the doubly linklist :\n");
    scanf("%d", &integer);
    temporary = head;
    while (temporary != NULL)
    {
        if (integer == temporary->data)
        {
            break;
        }
        else
            temporary = temporary->next;

        ind++;
    }
    position = ind + 1;
    if (position < 1 || position > n)
        printf("Element Not found\n");
    else
    {
        if (position == 1)
        {
            head = deleteFromBeg(head, position);
        }
        else if (position == n)
        {
            head = deleteFromEnd(head, position);
        }
        else
        {
            head = deleteFromAnyPos(head, position);
        }
    }
    temporary = head;
    printf("After Deletion of the integer our Linked List Looks like :\n");
    while (temporary != NULL)
    {
        printf("%d\n", temporary->data);
        temporary = temporary->next;
    }
    return 0;
}