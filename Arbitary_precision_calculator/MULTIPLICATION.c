/*
Name        : Abhishek Y
Project     : Arbitrary Precision Calculator (APC)
File        : MULTIPLICATION.c
Description : Performs multiplication of two large numbers using
              repeated digit multiplication and shifting.
*/

#include "apc.h"

int multiply_numbers(Node *head1, Node *tail1,
                     Node *head2, Node *tail2,
                     Node **res_head, Node **res_tail)
{
    Node *ptr2 = tail2;
    int zeros = 0;

    // Initialize result as 0
    dl_insert_first(res_head, res_tail, 0);

    while (ptr2 != NULL)
    {
        Node *temp_head = NULL, *temp_tail = NULL;
        Node *ptr1 = tail1;

        int carry = 0;

        // Step 1: multiply one digit
        while (ptr1 != NULL)
        {
            int prod = ptr1->digit * ptr2->digit + carry;
            carry = prod / 10;

            dl_insert_first(&temp_head, &temp_tail, prod % 10);

            ptr1 = ptr1->prev;
        }

        if (carry > 0)
        {
            dl_insert_first(&temp_head, &temp_tail, carry);
        }

        // Step 2: add zeros (shifting)
        for (int i = 0; i < zeros; i++)
        {
            insert_at_end(&temp_head, &temp_tail, 0);
        }

        // Step 3: add temp result to final result
        Node *new_head = NULL, *new_tail = NULL;
        add_numbers(*res_head, *res_tail,
                    temp_head, temp_tail,
                    &new_head, &new_tail);

        // free old result
        free_list(*res_head);

        *res_head = new_head;
        *res_tail = new_tail;

        // free temp list
        free_list(temp_head);

        zeros++;
        ptr2 = ptr2->prev;
    }

    // Remove leading zeros
    while (*res_head && (*res_head)->digit == 0 && (*res_head)->next != NULL)
    {
        Node *temp = *res_head;
        *res_head = (*res_head)->next;
        (*res_head)->prev = NULL;
        free(temp);
    }

    return SUCCESS;
}