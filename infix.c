#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX 5

char STACK[MAX];
char POST[MAX];

int top = -1;
int pt = -1;

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

int precidence(char op)
{
    switch (op)
    {
    case '+':
    case '-':
        return 1;

    case '/':
    case '*':
    case '%':
        return 2;

    case '^':
        return 3;

    default:
        return 0;
    }
}

char *infix(char *exp)
{
    int i = 0;

    while (exp[i] != '\0')
    {

        if (isalpha(exp[i]))
        {
            pt++;
            POST[pt] = exp[i];
        }

        else if (exp[i] == '(')
        {
            if (isFull())
                printf("Stack full");
            else
            {
                top++;
                STACK[top] = exp[i];
            }
        }

        else if (exp[i] == ')')
        {
            while (!isEmpty() && STACK[top] != '(')
            {
                pt++;
                POST[pt] = STACK[top];
                top--;
            }

            if (!isEmpty() && STACK[top] == '(')
                top--;
        }

        else if (exp[i] == '+' || exp[i] == '-' || exp[i] == '/' || exp[i] == '*' || exp[i] == '%' || exp[i] == '^')
        {
            while (!isEmpty() && STACK[top] != '(' && precidence(STACK[top]) >= precidence(exp[i]))
            {
                pt++;
                POST[pt] = STACK[top];
                top--;
            }

            if (isFull())
            {
                printf("Stack full\n");
                return POST;
            }

            top++;
            STACK[top] = exp[i];
        }

        i++;
    }

    while (!isEmpty())
    {
        pt++;
        POST[pt] = STACK[top];
        top--;
    }

    return POST;
}

int main()
{

    char *postfix;

    postfix = infix("(a+b)");
    printf("%s", postfix);

    return 0;
}