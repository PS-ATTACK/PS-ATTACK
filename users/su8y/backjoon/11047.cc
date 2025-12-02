/* 10 4200
1
5
10
50
100
500
1000
5000
10000
50000 
규가 가지고 있는 동전은 총 N종류이고, 각각의 동전을 매우 많이 가지고 있다.

동전을 적절히 사용해서 그 가치의 합을 K로 만들려고 한다. 이때 필요한 동전 개수의 최솟값을 구하는 프로그램을 작성하시오.
4500이 있으면 
높은 수부터 
1빼면서 안빼진다면 (- > 0)
다음수로 넘어가고 
k = 0 이 된다면 다 빼진것이므로 종료 
*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int cnt = 0;
    int res = 0;
    int n, k;    // 동전종류의 개수 , 금액
    int *numPtr; //동전들의 종료 : 동적으로 메모리를 할당받음
    scanf("%d %d", &n, &k);

    numPtr = (int *)malloc(sizeof(int) * n); // 동적으로 메모리를할당받으

    // 입력
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &numPtr[i]);
    } // 끝

    //풀이과정은 numPtr 의 값을 입력받은 것들은
    for (int i = n - 1; i >= 0; i--)
    {
        if (k == 0)
            break;
        if (k >= numPtr[i])
        {
            res = k / numPtr[i];
            cnt += res;
            k = k - (res * numPtr[i]);
            /*  */
        }
    }

    printf("%d", cnt);

    free(numPtr);
    return 0;
}