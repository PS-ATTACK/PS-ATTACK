#include <stdio.h>
//33 은 39 의 생성자  생성자가 없는 숫자를 셀프넘버라고 한다 .
static int ARR[10001];
int self_num(int n);
int main()
{
    int i;
    int res;
    for (i = 0; i < 10001; i++)
    {
        res = self_num(i);
        if (ARR[i] < 10001)
            ARR[res] = 1;

        if (ARR[i] != 1)
        {
            printf("%d\n", i);
        }
    }

    return 0;
}
//셀프넘버가 아닌 수를 구하자
int self_num(int n)
{
    int r = n;
    while (n > 0)
    {

        r = r + n % 10;
        n = n / 10;
    }

    return r;
}