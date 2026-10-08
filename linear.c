#include <stdio.h>
#include <stdbool.h>
#include "malloc.h"

int main()
{

    int n;
    int sk;
    bool found;

    printf("Enter the size of array: ");
    scanf("%d", &n);

    int *arr = malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
    {
        printf("Enter element %d: ", i);
        scanf("%d", &arr[i]);
    }

    printf("Enter the element to search");
    scanf("%d", &sk);

    for (int i = 0; i < n; i++)
    {

        if (arr[i] == sk)
        {
            printf("Element found at %d", i + 1);
            found = true;
        }
    }

    if (!found)
        printf("Element not found");

    return 0;
}
