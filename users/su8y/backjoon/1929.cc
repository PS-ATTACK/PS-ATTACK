#include <stdio.h>

int arr[1000001] = {0};
int main()
{
    int m, n;

    scanf("%d %d", &m, &n);
    arr[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        for (int j = i + i; j < 1000000; j += i)
        {
            arr[j] = 1;
        }
    }
    for (int i = m; i <= n; i++)
    {
        if (arr[i] == 0)
            printf("%d\n", i);
    }

    return 0;
}