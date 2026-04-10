/*
Name        : Abhishek Y
Project     : Arbitrary Precision Calculator (APC)
File        : APC_main.c
Description : Main driver file. Takes input from command line,
              processes operators (+, -, *, /), and calls
              corresponding arithmetic functions.
*/

#include <stdio.h>
#include "apc.h"

int main(int argc, char *argv[])
{
    if (argc != 4)
    {
        printf("Usage: %s <num1> <operator> <num2>\n", argv[0]);
        return 1;
    }

    char *num1 = argv[1];
    char *op = argv[2];
    char *num2 = argv[3];

    int sign1 = 1, sign2 = 1;
    if (num1[0] == '-')
    {
        sign1 = -1;
        num1++; // skip '-'
    }

    if (num2[0] == '-')
    {
        sign2 = -1;
        num2++; // skip '-'
    }

    Node *head1 = NULL, *tail1 = NULL;
    Node *head2 = NULL, *tail2 = NULL;
    Node *res_head = NULL, *res_tail = NULL;

    // convert strings to DLL
    if (create_list_from_string(&head1, &tail1, num1) == FAILURE ||
        create_list_from_string(&head2, &tail2, num2) == FAILURE)
    {
        printf("Invalid input\n");
        return 1;
    }

    // check operator
    switch (op[0])
    {
    case '+':
        printf("Result: ");

        // Case 1: same sign → normal addition
        if (sign1 == sign2)
        {
            add_numbers(head1, tail1, head2, tail2, &res_head, &res_tail);

            if (sign1 == -1)
                printf("-");

            print_list(res_head);
        }
        else
        {
            // convert to subtraction
            int cmp = compare_numbers(head1, head2);

            if (cmp == 0)
            {
                printf("0");
            }
            else if (cmp > 0)
            {
                subtract_numbers(head1, tail1, head2, tail2, &res_head, &res_tail);

                if (sign1 == -1)
                    printf("-");

                print_list(res_head);
            }
            else
            {
                subtract_numbers(head2, tail2, head1, tail1, &res_head, &res_tail);

                if (sign2 == -1)
                    printf("-");

                print_list(res_head);
            }
        }

        printf("\n");
        break;

    case '-':
        printf("Result: ");

        // Convert subtraction into addition
        // a - b = a + (-b)

        // Case 1: signs are different → addition
        if (sign1 != sign2)
        {
            add_numbers(head1, tail1, head2, tail2, &res_head, &res_tail);

            if (sign1 == -1)
                printf("-");

            print_list(res_head);
        }
        else
        {
            // same sign → subtraction
            int cmp = compare_numbers(head1, head2);

            if (cmp == 0)
            {
                printf("0");
            }
            else if (cmp > 0)
            {
                subtract_numbers(head1, tail1, head2, tail2, &res_head, &res_tail);

                if (sign1 == -1)
                    printf("-");

                print_list(res_head);
            }
            else
            {
                subtract_numbers(head2, tail2, head1, tail1, &res_head, &res_tail);

                if (sign1 == 1)
                    printf("-");
                // if sign1 == -1 → result is positive

                print_list(res_head);
            }
        }

        printf("\n");
        break;

    case '*':
        multiply_numbers(head1, tail1, head2, tail2, &res_head, &res_tail);

        printf("Result: ");

        if (sign1 * sign2 == -1)
            printf("-");

        print_list(res_head);
        printf("\n");
        break;

    case '/':
        if (divide_numbers(head1, tail1, head2, tail2, &res_head, &res_tail) == FAILURE)
        {
            printf("Error: Division failed\n");
        }
        else
        {
            printf("Result: ");

            if (sign1 * sign2 == -1)
                printf("-");

            print_list(res_head);
            printf("\n");
        }
        break;

    default:
        printf("Invalid operator\n");
    }

    // free memory
    free_list(head1);
    free_list(head2);
    free_list(res_head);

    return 0;
}