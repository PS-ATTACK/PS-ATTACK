#include <stdio.h>

int main()
{
    int i, j, n;
    static int a = 1;
    scanf("%d", &n);

    for (i = 0; i < n; i++) //5열
    {
        //총 n번 반복출력 i가 1이라면 1,2라면 2
        for (j = 0; j < n; j++)
        {
            if (j + 1 < n - i)
                printf(" ");
            else
                printf("*");
        }
        printf("\n");
    }

    return 0;
}