#include <stdio.h>

int main()
{
    auto int x, y;

    scanf("%d %d", &x, &y);

    //제 1사분면 x + ,y +
    if ((x >= 0) && (y >= 0))
        printf("1\n");
    //제 2 사분면 x - , y +
    else if ((x < 0) && (y >= 0))
        printf("2");
    else if ((x < 0) && (y < 0))
        printf("3");
    else
        printf("4");

    return 0;
}