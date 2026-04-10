/*
Name        : Abhishek Y
Project     : Arbitrary Precision Calculator (APC)
File        : APC.h
Description : Header file containing structure definitions, macros,
              and function prototypes used throughout the project.
*/

#ifndef APC_H
#define APC_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// return status
#define SUCCESS 0
#define FAILURE -1

// Node structure (DLL)
typedef struct node
{
    int digit;
    struct node *prev;
    struct node *next;
} Node;

// ===== DLL FUNCTIONS =====
int insert_at_end(Node **head, Node **tail, int digit);
int dl_insert_first(Node **head, Node **tail, int data);
void print_list(Node *head);
void free_list(Node *head);

// ===== CONVERSION =====
int create_list_from_string(Node **head, Node **tail, char *str);

// ===== APC OPERATIONS =====
int add_numbers(Node *head1, Node *tail1,
                Node *head2, Node *tail2,
                Node **res_head, Node **res_tail);

int compare_numbers(Node *head1, Node *head2);

int subtract_numbers(Node *head1, Node *tail1,
                     Node *head2, Node *tail2,
                     Node **res_head, Node **res_tail);

int multiply_numbers(Node *head1, Node *tail1,
                     Node *head2, Node *tail2,
                     Node **res_head, Node **res_tail);

int divide_numbers(Node *head1, Node *tail1,
                   Node *head2, Node *tail2,
                   Node **res_head, Node **res_tail);

#endif