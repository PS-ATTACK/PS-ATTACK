#include <stdio.h>
#include <string.h>
char ARR[100];

int main()
{
    int n, i, j, cnt = 1; //cnt O 연속된 개수 측정
    static int value;     //결과값 저장


    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        
        scanf("%s", ARR);

        for (j = 0; j < strlen(ARR); j++)
        {
            if (ARR[j] == 'O')
            {

                value = value + cnt;
                cnt++;
            }
            else if (ARR[j] == 'X')
            {
                cnt = 1;
            }
        }
        printf("%d\n", value);
        value = 0;
        cnt = 1;
    }

    return 0;
}