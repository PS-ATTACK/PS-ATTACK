#include <stdio.h>
/* 한수는 지금 (x, y)에 있다. 직사각형의 왼쪽 아래 꼭짓점은 (0, 0)에 있고, 오른쪽 위 꼭짓점은 (w, h)에 있다. 직사각형의 경계선까지 가는 거리의 최솟값을 구하는 프로그램을 작성하시오. 
1 ≤ w, h ≤ 1,000
1 ≤ x ≤ w-1
1 ≤ y ≤ h-1
x, y, w, h는 정수
6 2 10 3 
6 2
10 3 
이면 abs(x) > abs(x - w)
*/
#include <stdlib.h> // abs() 함수 사용이유
#define MIN(a, b) a < b ? a : b
#define MAX(a, b) a > b ? a : b
int main()
{
    int x, y, w, h;
    int min_x, min_y;
    scanf("%d %d %d %d", &x, &y, &w, &h);
    min_x = MIN(x, abs(x - w)); //x갑 중에서 최소값
    min_y = MIN(y, abs(y - h));

    printf("%d", MIN(min_x, min_y));

    return 0;
}