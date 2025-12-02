#include <stdio.h>

int main()
{
    
    int num1, num2;
    int out1, out2, out3, res;

    scanf("%d %d", &num1, &num2);

    out1 = (num2 % 100) % 10;          //1의 자리
    out2 = ((num2 % 100) - out1) / 10; //10의 자리
    out3 = (num2 - out2) / 100;        //100의 자리
    res = num1 * num2;


    printf("%d\n%d\n%d\n%d\n", num1 * out1, num1 * out2, num1 * out3, res);

    return 0;
}