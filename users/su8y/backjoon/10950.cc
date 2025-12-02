#include <stdio.h>

int main(void)
{
    int n;
    int a, b;
    int r[100];
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &a, &b);
        r[i] = a + b;
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d\n", r[i]);
    }
}
