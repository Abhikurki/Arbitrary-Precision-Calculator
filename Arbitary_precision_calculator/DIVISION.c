/*
Name        : Abhishek Y
Project     : Arbitrary Precision Calculator (APC)
File        : DIVISION.c
Description : Performs division of two large numbers using
              repeated subtraction method.
*/

#include "apc.h"

int divide_numbers(Node *head1, Node *tail1,
                   Node *head2, Node *tail2,
                   Node **res_head, Node **res_tail)
{
    // Division by zero check
    if (head2 == NULL || (head2->digit == 0 && head2->next == NULL))
    {
        return FAILURE;
    }

    // If num1 < num2 → result = 0
    if (compare_numbers(head1, head2) < 0)
    {
        dl_insert_first(res_head, res_tail, 0);
        return SUCCESS;
    }

    Node *temp_head = NULL, *temp_tail = NULL;
    Node *quot_head = NULL, *quot_tail = NULL;

    // copy num1 into temp (so original is safe)
    Node *ptr = head1;
    while (ptr)
    {
        insert_at_end(&temp_head, &temp_tail, ptr->digit);
        ptr = ptr->next;
    }

    int count = 0;

    //repeated subtraction
    while (compare_numbers(temp_head, head2) >= 0)
    {
        Node *new_head = NULL, *new_tail = NULL;

        subtract_numbers(temp_head, temp_tail,
                         head2, tail2,
                         &new_head, &new_tail);

        free_list(temp_head);

        temp_head = new_head;
        temp_tail = new_tail;

        count++;
    }

    // convert count → DLL
    if (count == 0)
    {
        dl_insert_first(res_head, res_tail, 0);
    }
    else
    {
        while (count > 0)
        {
            dl_insert_first(res_head, res_tail, count % 10);
            count /= 10;
        }
    }

    return SUCCESS;
}