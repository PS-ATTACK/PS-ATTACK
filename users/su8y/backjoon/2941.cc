#include <stdio.h>
#include <string.h>

int main()
{
    char croatia[100];
    int apb_len; //크로아티아알파벳길이
    scanf("%s", croatia);
    //우선 글자길이를 정한다음 크로아티아 문자가있으면 빼면서 길이를 측정하는 방식을 사용할거임
    apb_len = strlen(croatia);

    for (int i = 0; i < strlen(croatia); i++)
    {
        if ((croatia[i] == 'l' || croatia[i] == 'n') && croatia[i + 1] == 'j')
            apb_len--;
        if (croatia[i] == 'd' && croatia[i + 1] == 'z' && croatia[i + 2] == '=')
            apb_len--;
        if (croatia[i] == '-' || croatia[i] == '=')
            apb_len--;
    }
    printf("%d\n", apb_len);

    return 0;
}
