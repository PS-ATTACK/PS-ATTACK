/************************************************************************
 1546평균.c 
 M = 최대값이 되고 
 m/ 점수 /* 100 이 되어 점수를 매긴다 .?
 n 과목의 계수 
 **********************************************************************/
#include <stdio.h>

int MAX(int *arr, int n);
int main()
{
    int N, M, i;

    double sum = 0;

    scanf("%d", &N);

    int grade[N];
    for (i = 0; i < N; i++)
    {
        scanf("%d", &grade[i]);
    }
    M = MAX(grade, N);

    for (i = 0; i < N; i++)
    {
        sum += (double)grade[i] / (double)M * 100;
    }
    printf("%.2f\n", (double)sum / (double)N);

    return 0;
}
int MAX(int *arr, int n)
{
    int i;
    int max_value = arr[0];

    for (i = 0; i < n; i++)
    {
        if (max_value < arr[i])
            max_value = arr[i];
    }

    return max_value;
}