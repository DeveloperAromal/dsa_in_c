#include <stdio.h>
#include <stdbool.h>

#define MAX 5

int top = -1;
int STACK[MAX];

bool isEmpty()
{
    if (top == -1)
        return true;
    else
        return false;
}

bool isFull()
{
    if (top == MAX - 1)
        return true;
    else
        return false;
}

void push(int val)
{
    if (isFull())
        printf("Stack full\n");
    else
    {
        top++;
        STACK[top] = val;
    }
}

void pop()
{
    if (isEmpty())
        printf("Stack empty\n");
    else
        top--;
}

void display()
{
    if (isEmpty())
        printf("stack empty\n");
    else
    {
        for (int i = top; i >= 0; i--)
            printf("%d  ", STACK[i]);
        printf("\n");
    }
}

int main()
{

    push(10);
    push(20);
    push(30);
    display();

    pop();
    pop();
    display();

    return 0;
}