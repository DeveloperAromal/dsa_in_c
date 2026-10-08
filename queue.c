#include <stdio.h>
#include <stdbool.h>

#define MAX 5

int rear = -1;
int front = -1;

int QUEUE[MAX];

bool isOverflowed()
{
    if (rear == MAX - 1)
        return true;
    else
        return false;
}

bool isUnderflowed()
{
    if (front == -1 || front > rear)
        return true;
    else
        return false;
}

void enqueue(int val)
{
    if (isOverflowed())
        printf("Queue overflowed");
    else
    {
        if (front == -1)
            front = 0;

        rear++;

        QUEUE[rear] = val;
    }
}

void dequeue()
{
    if (isUnderflowed())
        printf("Queue underflow");
    else
        front++;
}

void display()
{
    if (isUnderflowed())
        printf("Queue empty");

    for (int i = front; i <= rear; i++)
        printf("%d  ", QUEUE[i]);

    printf("\n");
}

int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    display();

    dequeue();
    dequeue();
    display();

    return 0;
}
