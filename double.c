#include <stdio.h>
#include "malloc.h"

struct NODE
{
    int data;
    struct NODE *left;
    struct NODE *right;
};

struct NODE *head = NULL;

struct NODE *create_node(int value)
{

    struct NODE *node = malloc(sizeof(struct NODE));

    node->data = value;
    node->left = NULL;
    node->right = NULL;

    return node;
}

void insert_front(int val)
{

    struct NODE *new_node = create_node(val);

    new_node->left = head;

    if (head != NULL)
        head->right = new_node;

    head = new_node;
}

void insert_end(int val)
{

    struct NODE *new_node = create_node(val);

    if (head == NULL)
    {
        printf("List empty\n");
        return;
    }

    struct NODE *temp = head;

    while (temp->left != NULL)
        temp = temp->left;

    temp->left = new_node;
    new_node->right = temp; //
}

void insert_at_any(int val, int pos)
{

    struct NODE *new_node = create_node(val);

    if (pos == 1)
    {
        insert_front(val);
        return;
    }

    struct NODE *temp = head;

    for (int i = 1; i < pos - 1; i++)
    {
        if (temp == NULL)
            free(new_node);

        temp = temp->left;
    }

    if (temp == NULL)
        free(new_node);

    new_node->left = temp->left;
    new_node->right = temp;

    if (temp->left != NULL)
    {
        temp->left->right = new_node;
    }

    temp->left = new_node;
}

void display()
{
    struct NODE *temp = head;

    if (head == NULL)
    {
        printf("List empty\n");
        return;
    }

    while (temp != NULL)
    {
        printf("%d <->", temp->data);
        temp = temp->left;
    }
}

int main()
{

    insert_front(10);
    insert_front(20);

    insert_end(30);
    insert_end(40);

    insert_at_any(30, 3);

    display();

    return 0;
}