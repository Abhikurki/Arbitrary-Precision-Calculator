/*
Name        : Abhishek Y
Project     : Arbitrary Precision Calculator (APC)
File        : DLL.c
Description : Implements Doubly Linked List operations such as
              insertion, printing, and memory management.
*/

//Double linked list
#include "apc.h"

int insert_at_end(Node **head, Node **tail, int digit)
{
    Node *newnode = malloc(sizeof(Node));

    if(newnode == NULL)
        return FAILURE;

    newnode->digit = digit;
    newnode->next = NULL;
    newnode->prev = *tail;

    if(*head == NULL)
    {
        *head = *tail = newnode;
    }
    else
    {
        (*tail)->next = newnode;
        *tail = newnode;
    }

    return SUCCESS;
}

int dl_insert_first(Node **head, Node **tail, int data)
{
    Node *new = malloc(sizeof(Node));
    if (new == NULL)
        return FAILURE;

    new->digit = data;
    new->prev = NULL;
    new->next = *head;

    if (*head == NULL)
    {
        *head = *tail = new;
    }
    else
    {
        (*head)->prev = new;
        *head = new;
    }

    return SUCCESS;
}

void print_list(Node *head)
{
    while(head)
    {
        if(head->digit == -1)
        {
            printf("-");
        }
        else
        {
            printf("%d", head->digit);
        }
        head = head->next;
    }
}

void free_list(Node *head)
{
    Node *temp;
    while(head)
    {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int compare_numbers(Node *head1, Node *head2)
{
    Node *temp1 = head1;
    Node *temp2 = head2;

    // Step 1: count length of both lists
    int len1 = 0, len2 = 0;

    while (temp1)
    {
        len1++;
        temp1 = temp1->next;
    }

    while (temp2)
    {
        len2++;
        temp2 = temp2->next;
    }

    // Step 2: compare lengths
    if (len1 > len2)
        return 1;
    else if (len1 < len2)
        return -1;

    // Step 3: same length → compare digit by digit
    temp1 = head1;
    temp2 = head2;

    while (temp1 && temp2)
    {
        if (temp1->digit > temp2->digit)
            return 1;
        else if (temp1->digit < temp2->digit)
            return -1;

        temp1 = temp1->next;
        temp2 = temp2->next;
    }

    return 0; // equal
}