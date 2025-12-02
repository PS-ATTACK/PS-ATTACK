#include <stdio.h>
#include <stdbool.h>

int T, ANS = 0, tmp;
bool prime(int prime)
{
    if (prime == 1)//1은 소수가 아님 
        return false;
    for (int i = 2; i < prime; i++) 
    {
        if (prime % i == 0)//prime 보다 낮은수로 나누고 나눠진다면 소수가 아님 
        {
            return false;
        }
    }
    return true; // 소수면 true를 반환 
}
int main()
{
    scanf("%d", &T);

    while (T--) // t만큼 반복
    {
        scanf("%d", &tmp);

        if (prime(tmp))
        {
            ANS++;
        }
    }
    printf("%d", ANS);
    return 0;
}