#include <stdio.h>
#include <stdlib.h>

//케이스 c 학생수 n 점수 score
//avg = score / n
FILE dfdfsdf;
//평균을 넘은 학생 소수점 3 자리까지
int main()
{
    int C, N, count = 0;
    int i, j;
    double avg;
    int sum = 0;
    scanf("%d", &C);

    for (i = 0; i < C; i++)
    {
        scanf("%d", &N); //학생의 수 입력
        sum = 0;
        //학생의 점수의 메모리를 동적할당함.
        // N_score = (int *)malloc(sizeof(int) * N);
        int N_score[N];
        for (j = 0; j < N; j++)
        {
            scanf("%d", &N_score[j]);

            sum += N_score[j];
        }

        avg = (double)sum / (double)N;

        count = 0;

        for (j = 0; j < N; j++)
        {
            if (avg < N_score[j])
                count++;
        }
        printf("%.3f%%\n", (double)count / (double)N * 100);
    }

    return 0;
}