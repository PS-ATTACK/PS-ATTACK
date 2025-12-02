#include <stdio.h>

int main()
{
    int a;
    scanf("%d", &a);
    //윤년은 연도가 4의 배수이면서, 100의 배수가 아닐 때 또는 400의 배수일 때이다.

    if (((a % 4 == 0) && (a % 100 != 0)) || a % 400 == 0)
    {
        printf("1\n");
    }
    else
        printf("0\n");

    return 0;
}