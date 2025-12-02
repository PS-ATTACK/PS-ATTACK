//A = 고정지출
//B = 가변비용
//C = 판매비용
//손익분기점이 존재하지않으면 -1 을 출력한다 .
#include <stdio.h>

int BREAK_EVEN_POINT(int fixed_spend, int cost_variable, int cost_sales);

int main()
{
    int A, B, C;
    int result = 0;
    scanf("%d %d %d", &A, &B, &C);
    result = BREAK_EVEN_POINT(A, B, C);
    printf("%d", result);
    return 0;
}
int BREAK_EVEN_POINT(int fixed_spend, int cost_variable, int cost_sales)
{
    int cnt = 0;
    long i = 0;
    if (cost_variable >= cost_sales)
        return -1;
    i = fixed_spend / (cost_sales - cost_variable) + 1;
    return i;
}