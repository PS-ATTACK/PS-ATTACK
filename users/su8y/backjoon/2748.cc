#include <stdio.h>
/* 피보나치수 n 번째 피보나치수를 구하는 프로그램을 구하시오
0 , 1 , 1 , 2 ,3 ... p , pp -> pp + p
 */
long long pib(int n);
int main()
{
    int n;
    long long r; // pib() 값을 받을 변수
    scanf("%d", &n);

    r = pib(n);

    printf("%lld", r);
    return 0;
}
long long pib(int n)
{
    long long tmp, p = 0, pp = 1; //피보나치수를 대입할 함수 ;
                                  // p + pp 값을 넣어주는 변수;
    if (n == 0)
        return 0;

    else if (n == 1)
        return 1;
    else
    {
        for (int i = 1; i < n; i++)
        {
            tmp = p + pp;
            p = pp;
            pp = tmp;
        }
        return tmp;
    }
}