#include <stdio.h>

int main()
{
    int n;
    int i, a, b;
    static int sum[100000000];
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        scanf("%d %d", &a, &b);
        sum[i] = a + b;
    }
    for (i = 0; i < n; i++)
    {
        printf("%d\n", sum[i]);
    }

    return 0;
}