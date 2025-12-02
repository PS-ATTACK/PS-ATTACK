#include <stdio.h>

int main()
{
    int i, j, n;
    static int a = 1;
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < a; j++)
        {
            printf("*");
                }
        a++;
        printf("\n");
    }

    return 0;
}