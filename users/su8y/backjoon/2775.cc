#include <stdio.h>

int main()
{
    int T, k, n; //층 호수
    int arr[15][15] = {0};
    scanf("%d", &T);

    for (int i = 0; i < 15; i++)
    {
        for (int j = 1; j <= 14; j++)
        {
            if (i == 0)
                arr[i][j] = j;
            else
            {
                arr[i][j] = arr[i - 1][j] + arr[i][j - 1];
            }
        }
    }
    for (int i = 0; i < T; i++)
    {
        scanf("%d\n%d", &k, &n);
        printf("%d\n", arr[k][n]);
    }
    return 0;
}