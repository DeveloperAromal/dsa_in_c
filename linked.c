#include <stdio.h>
#include "malloc.h"

struct NODE
{
    int data;
    struct NODE *next;
};

struct NODE *head = NULL;

struct NODE *create_node(int value)
{

    struct NODE *node = malloc(sizeof(struct NODE));

    node->data = value;
    node->next = NULL;

    return node;
}

void insert_front(int val)
{

    struct NODE *new_node = create_node(val);

    new_node->next = head;
    head = new_node;
}

void insert_end(int val)
{

    struct NODE *new_node = create_node(val);

    if (head == NULL)
        head = new_node;

    struct NODE *temp = head;

    while (temp->next != NULL)
        temp = temp->next;

    temp->next = new_node;
}

void insert_at_any(int val, int pos)
{

    struct NODE *new_node = create_node(val);

    if (pos == 1)
        insert_front(val);

    struct NODE *temp = head;

    for (int i = 1; i < pos - 1; i++)
    {
        if (temp == NULL)
            free(new_node);

        temp = temp->next;
    }

    if (temp == NULL)
        free(new_node);

    new_node->next = temp->next;
    temp->next = new_node;
}

void display()
{
    struct NODE *temp = head;

    if (head == NULL)
        printf("list empty");

    while (temp != NULL)
    {
        printf("%d ->", temp->data);
        temp = temp->next;
    }
}

int main()
{

    insert_front(10);
    insert_front(20);

    insert_end(30);
    insert_end(40);

    display();

    return 0;
}