#include <stdio.h>
#include "malloc.h"

int main()
{

    int m, n;
    int z, nz;

    printf("Enter rows of matrix: ");
    scanf("%d", &m);

    printf("Enter columns of matrix: ");
    scanf("%d", &n);

    int arr[m][n];

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("Enter array element: ");
            scanf("%d", &arr[i][j]);
        }
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d\t", arr[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr[i][j] == 0)
                z++;
            else
                nz++;
        }
    }

    if (z > nz)
        printf("Sparse");
    else
        printf("Not sparse");

    return 0;
}