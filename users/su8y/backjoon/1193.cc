#include <stdio.h>
int main()
{
    int X, i, sum = 0, floor = 0, div;
    scanf("%d", &X);
    //몇번째 그룹인지 구하는 함수
    for (i = 0; i < X; i += sum)
    {
        sum++;
        floor++; //그룹 +1
    }
    div = X - (i - floor);// 그룹내에서의 위치
    for (int j = 0; j < floor; j++)
    {
        if (j == div - 1) // 그룹내에서의 위치가 맞다면 
        {
            if (floor % 2 == 0)

                printf("%d/%d ", j + 1, floor - j);
            else
                printf("%d/%d ", floor - j, j + 1);
        }
    }
    return 0;
}