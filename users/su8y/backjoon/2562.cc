#include <stdio.h>
/*************************************************************
3, 29, 38, 12, 57, 74, 40, 85, 61 최대값과 그 위치 index를 구하여라
*************************************************************/
int main(void)
{
    int array[9];
    static int max = -1;
    int index;
    int i;
    for (i = 0; i < 9; i++)
    {
        scanf("%d", &array[i]);
        if (max < array[i])
        {
            max = array[i];
            index = i;
        }
    }

    printf("%d\n%d", array[index], index + 1);
}