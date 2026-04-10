/*
Name        : Abhishek Y
Project     : Arbitrary Precision Calculator (APC)
File        : SUBSTRACTION.c
Description : Performs subtraction of two large numbers using
              Doubly Linked List and handles borrow and sign.
*/

#include "apc.h"

int subtract_numbers(Node *head1, Node *tail1,
                     Node *head2, Node *tail2,
                     Node **res_head, Node **res_tail)
{
    // Step 1: compare numbers
    int cmp = compare_numbers(head1, head2);

    // If equal → result = 0
    if (cmp == 0)
    {
        dl_insert_first(res_head, res_tail, 0);
        return SUCCESS;
    }

    // If num1 < num2 → swap
    int is_negative = 0;
    if (cmp < 0)
    {
        Node *temp_head = head1;
        Node *temp_tail = tail1;

        head1 = head2;
        tail1 = tail2;

        head2 = temp_head;
        tail2 = temp_tail;

        is_negative = 1;
    }

    Node *ptr1 = tail1;
    Node *ptr2 = tail2;

    int borrow = 0;

    while (ptr1 != NULL || ptr2 != NULL)
    {
        int a = 0, b = 0;

        if (ptr1 != NULL)
        {
            a = ptr1->digit;
            ptr1 = ptr1->prev;
        }

        if (ptr2 != NULL)
        {
            b = ptr2->digit;
            ptr2 = ptr2->prev;
        }

        a = a - borrow;

        if (a < b)
        {
            a += 10;
            borrow = 1;
        }
        else
        {
            borrow = 0;
        }

        dl_insert_first(res_head, res_tail, a - b);
    }

    // Remove leading zeros
    while (*res_head && (*res_head)->digit == 0 && (*res_head)->next != NULL)
    {
        Node *temp = *res_head;
        *res_head = (*res_head)->next;
        (*res_head)->prev = NULL;
        free(temp);
    }

    // Print negative sign if needed
    if (is_negative)
    {
        dl_insert_first(res_head, res_tail, -1);
    }

    return SUCCESS;
}