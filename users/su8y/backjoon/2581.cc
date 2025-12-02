#include <stdio.h>

int main()
{
    int N, M;
    int min = 10001, sum = 0, flags;

    scanf("%d %d", &N, &M);

    for (int i = N; i <= M; i++)
    {
        flags = 0;
        for (int j = 2; j < i; j++)
        {
            if (i % j == 0)
                flags = 1; //  소수가 아님
        }

        if (flags == 0 && i != 1)
        {
            sum += i;
            if (min > i)
                min = i;
        }
    }

    if (min == 10001)
        printf("-1");
    else
    {
        printf("%d\n", sum);
        printf("%d", min);
    }
}