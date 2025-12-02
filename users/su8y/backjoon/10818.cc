#include <stdio.h>
#include <stdlib.h>

//후 최소값과 초댓값을 공백으로 출력함

int main(void)
{
    int n, i;
    int *array;
    int min = 1000000, max = -1000000; //최소 와 최대
    scanf("%d", &n);

    array = (int *)malloc(sizeof(int) * n);

    for (i = 0; i < n; i++)
    {
        scanf("%d", array + i);
        if (min > *(array + i))
        {
            min = *(array + i);
        }
        if (max < *(array + i))
        {
            max = *(array + i);
        }
    }
    printf("%d %d", min, max);
}