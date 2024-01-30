#include <string.h>
#include <stdio.h>
//등차수열 한수 머라는거야 샤발 그냥 만들자 ..
int length(int l);
int num(int n);
int main()
{
    int N, cnt = 0;
    scanf("%d", &N);
    for (int i = 1; i <= N; i++)
    {
        if (num(i) == 1)
        {
            cnt = cnt + 1;
        }
    }
    printf("%d\n", cnt);
    return 0;
}

int num(int n)
{
    int l = length(n);
    if (l <= 2)
        return 1;
    else
    {
        int sml = n % 10;
        n /= 10;
        int big = n % 10;
        int diff = sml - big;

        for (int i = 0; i < l - 2; i++)
        {
            sml = big;
            big = (n / 10) % 10;

            if (diff != sml - big)
                return 0;
            n /= 10;
        }
        return 1;
    }
}
int length(int l)
{
    int res = 0;
    while (l > 0)
    {
        l = l / 10;
        res = res + 1;
    }

    return res;
}