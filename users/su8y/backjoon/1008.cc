#include <stdio.h>
int main()
{
    int a, b;
    scanf("%d %d", &a, &b);
    //정수형의 소수점을 표현하기 위하여  double 형을 사용함
    printf("%.9lf", (double)a / b);
    return 0;
}