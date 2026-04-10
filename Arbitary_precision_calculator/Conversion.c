/*
Name        : Abhishek Y
Project     : Arbitrary Precision Calculator (APC)
File        : Conversion.c
Description : Converts input number (string) into a Doubly Linked List
              where each node stores a single digit.
*/

#include "apc.h"

int create_list_from_string(Node **head, Node **tail, char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] >= '0' && str[i] <= '9')
        {
            insert_at_end(head, tail, str[i] - '0');
        }
        else
        {
            return FAILURE;
        }
    }
    return SUCCESS;
}