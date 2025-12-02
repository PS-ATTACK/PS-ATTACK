#include <iostream>
#include <string>

using namespace std;
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string str;

    getline(cin, str);
    int count = 1;
    //index[0] 에 공백이 있으면 하나뺌

    if (str[0] == ' ')
        count--;
    if (str[str.length() - 1] == ' ')
        count--;

    for (int i = 0; i < str.length(); ++i) {
        //공백있으면 하나 올림
        if (str[i] == ' ')
            count++;
        //공백이 중첩되면 하나 내림
        // if (str[i] == ' ' && str[i - 1] == ' ')
        //     count--;
    }

    cout << count << endl;
}