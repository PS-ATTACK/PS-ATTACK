#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int left_hand_cnt = 0, right_hand_cnt = 0;
int main() //string 문자열 stringn // char c 언어 스타일 지금
{
    string str;
    // char letf_hand[16] = {'q', 'w', 'e', 'r', 't', 'y', 'a', 's', 'd', 'f', 'g', 'z', 'x', 'c', 'v', 'b'};
    string left_hand{"qwertyasdfgzxcvb"};
    char right_hand[10] = {'u', 'i', 'o', 'p', 'h', 'j', 'k', 'l', 'n', 'm'};

    int cnt = 0;
    getline(cin, str);

    for (int i = 0; i < str.length(); i++) // str 사이즈만큼 반복
    {
        if (str[i] == ' ')
        {
            cnt++;
            continue;
        }
        if (str[i] >= 'A' && str[i] <= 'Z')
        {
            str[i] += 32;
            if (left_hand.find(str[i]) == string::npos)
            {
                cnt++;
                right_hand_cnt++;
            }
            else
            {
                cnt++;
                left_hand_cnt++;
            }
        }
        else
        {
            if (left_hand.find(str[i]) == string::npos)
                right_hand_cnt++;
            else
                left_hand_cnt++;
        }
    }
    while (cnt > 0)
    {
        right_hand_cnt >= left_hand_cnt ? left_hand_cnt++ : right_hand_cnt++;
        cnt--;
    }
    cout << left_hand_cnt << ' ' << right_hand_cnt  << endl;
}