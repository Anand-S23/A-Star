#ifndef DATA_STRUCTURES_H
#define DATA_STRUCTURES_H

/* Linked List */

typedef struct node
{
    struct node *next;
    cell *data;
} node;

typedef struct linked_list
{
    node *head; 
} linked_list;

#endif