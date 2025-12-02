#include <iostream>
#include <string>
#include <vector>

using namespace std;
int main() {
    int n, cnt = 0;
    char str[51];
    cin >> n;
    int i = 0;
    vector<char> v;
    cin.ignore();

    while(n--){
        i = 0; 
        v.clear();
        while (1) {
            scanf("%c", &str[i]);
            if (str[i] == '\n') break;
            i++;
        }
        for (int j = 0; j < i; j++) {
            if (str[j] == '(') {
                v.push_back(str[j]);
            }
            else if (str[j] == ')' && v.empty()) {
                v.push_back(str[j]);
            } 
            else if (str[j] == ')' && v.back() == '(') {
                v.pop_back();
            }
        }
        if (v.empty()) {
            printf("YES\n");
        } 
        else
            printf("NO\n");

    }


    return 0;
}