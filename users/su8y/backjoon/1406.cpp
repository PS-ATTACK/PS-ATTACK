#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

vector<char> solve(vector<char> answers);

int main() {
    string str;
    cin >> str;
    vector<char> v;
    for (int i = 0; i < str.length(); i++) {
        v.push_back(str[i]);
    }
    solve(v);
    return 0;
}
vector<char> solve(vector<char> answers) {
    vector<char> result;
    vector<char> vStack;
    char chr;
    int n;
    char chr2;
    cin >> n;
    cin.ignore();

    for (int i = 0; i < n; i++) {
        cin >> chr;
        cin.ignore();
        switch (chr) {
            case 'L':
                if (!answers.empty()) {
                    vStack.push_back(answers.back());
                    answers.pop_back();
                    // answers.erase(answers.end()-1);
                }
                break;
            case 'D':
                if (!vStack.empty()) {
                    answers.push_back(vStack.back());
                    vStack.pop_back();
                }
                break;
            case 'B':
                if (!answers.empty()) {
                    answers.pop_back();
                }
                break;
            case 'P':
                cin >> chr2;
                cin.ignore();
                answers.push_back(chr2);
                break;
        }
    }
    //문제 코드
    vector<char>::iterator it;
    for (int i = 0; i < vStack.size(); i++) {
        answers.push_back(vStack.back());
        vStack.pop_back();
    }
    for(it = answers.begin(); it != answers.end(); it++){
        cout << *it;
    }
    // 정답 코드
    // while(!vStack.empty()){
    //     answers.push_back(vStack.back());
    //     vStack.pop_back();
    // }
    // for(it = answers.begin(); it != answers.end(); it++){
    //     cout << *it;
    // }
    //문제코드를 없애고 이 밑에것을 주석풀면 맞음
    // vector<char>::reverse_iterator rit;
    // for (rit = vStack.rbegin(); rit != vStack.rend(); rit++) {
    //     cout << *rit;
    // }

    return result;
}
//출력
// vector<char>::iterator it;
// vector<char>::iterator it2;
// cout << "answer = ";
// for(it = answers.begin(); it != answers.end(); it++){
//     cout << *it << " ";
// }
// cout << endl;
// cout << "vStack = " ;
// for(it = vStack.begin(); it != vStack.end(); it++){
//     cout << *it << " ";
// }
// cout << endl;