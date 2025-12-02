#include <stdio.h>
#include <string.h>

int select(char a[], int len);

int main()
{
    int n, sum = 0;
    char arr[101];

    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%s", arr);
        sum += select(arr, strlen(arr));
    }
    printf("%d", sum);
    return 0;
}

int select(char a[], int len)
{
    int key = 0; //앞에 문자랑 비교하지 않게끔 해주는 키

    for (int i = 0; i < len; i++)
    {
        for (int j = i; j < len; j++)
        {
            if (a[i] == a[j])
            {
                if (j > i)
                    if (a[j - 1] != a[j])
                        return 0;
            }
        }
    }
    return 1;
}