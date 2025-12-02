#include <stdio.h>

int main()
{
    int i, t;
    int a, b;
    // static int sum[1000000];
    scanf("%d", &t);

    for (i = 0; i < t; i++)
    {
        scanf("%d %d", &a, &b);
        printf("Case #%d: %d\n", i + 1, a + b);

        // sum[i] = a + b;
    }

    // for (i = 0; i < t; i++)
    // {
    //     printf("Case #%d : %d\n", i + 1, sum[i]);
    // }

    return 0;
}