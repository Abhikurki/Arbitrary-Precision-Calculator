/*
Name        : Abhishek Y
Project     : Arbitrary Precision Calculator (APC)
File        : ADDITION.c
Description : Performs addition of two large numbers using
              Doubly Linked List and handles carry.
*/

#include "apc.h"

int add_numbers(Node *head1, Node *tail1,
                Node *head2, Node *tail2,
                Node **res_head, Node **res_tail)
{
    Node *ptr1 = tail1;
    Node *ptr2 = tail2;

    int carry = 0, sum, digit;

    while(ptr1 != NULL || ptr2 != NULL || carry)
    {
        int val1 = 0, val2 = 0;

        if(ptr1 != NULL) 
        {
            val1 = ptr1->digit;
            ptr1 = ptr1->prev;
        }

        if(ptr2 != NULL)
        {
            val2 = ptr2->digit;
            ptr2 = ptr2->prev;
        }

        sum = val1 + val2 + carry;

        digit = sum % 10;
        carry = sum / 10;

        // insert at front
        Node *newnode = malloc(sizeof(Node));
        if(newnode == NULL)
            return FAILURE;

        newnode->digit = digit;
        newnode->prev = NULL;
        newnode->next = *res_head;

        if(*res_head == NULL)
        {
            *res_head = *res_tail = newnode;
        }
        else
        {
            (*res_head)->prev = newnode;
            *res_head = newnode;
        }
    }

    return SUCCESS;
}