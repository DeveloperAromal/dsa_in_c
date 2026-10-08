#include <stdio.h>

struct poly
{
    int exp;
    float coeff;
} po[5];

int main()
{

    int deg;

    printf("Enter higher degree: ");
    scanf("%d", &deg);

    for (int i = 0; i <= deg; i++)
    {
        printf("Enter the coeff: ");
        scanf("%f", &po[i].coeff);

        po[i].exp = i;
    }

    for (int i = deg; i >= 0; i--)
    {
        printf("%.2fx^%d", po[i].coeff, po[i].exp);

        if (i != 0)
            printf(" + ");
    }

    return 0;
}