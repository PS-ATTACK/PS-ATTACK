#include <stdio.h>
#define DIV 42

int main()
{
    int i, a, res = 0;
    int cnt[DIV] = {0};

    for (i = 0; i < 10; i++)
    {
        scanf("%d", &a);

        cnt[a % DIV]++; //a % 42 의 값을 배열의 저장하여 하나씩올려줌
    }
    for (i = 0; i < DIV; i++) //대박이당. .
    {
        if (cnt[i] != 0)
        {
            res++;
        }
    }
    printf("%d\n", res);

    return 0;
}