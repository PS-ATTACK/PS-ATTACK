#include <stdio.h>
int fac(int n);
int main()
{
    int n = 0;
    scanf("%d", &n);
    printf("%d", fac(n));
    return 0;
}
int fac(int n)
{
    if (n == 1)
        return 1;
    if (n == 0)
        return 1;
    return n * fac(n - 1);
}
