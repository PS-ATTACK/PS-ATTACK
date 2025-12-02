#include <stdio.h>

long long sum(int *a, int n)
{
    long long r;
    for (int i = 0; i < n; i++)
    {
        r += a[i];
    }
    return r;
}