#include <stdio.h>

int main()
{
    int T, i, j; //test_case
    int height, width, customer;

    scanf("%d", &T);
    //w 방번호 h 층
    for (i = 0; i < T; i++)
    {
        scanf("%d %d %d", &height, &width, &customer);
        int start_number_room = 0, end_number_room = 0;
        for (j = 0; j < customer; j += height)
        {
            end_number_room++;
        }
        start_number_room = customer - (end_number_room - 1) * height;

        printf("%d%02d\n", start_number_room, end_number_room);
    }

    return 0;
}