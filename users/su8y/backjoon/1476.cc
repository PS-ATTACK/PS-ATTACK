#include <iostream>
//(1 ≤ E ≤ 15, 1 ≤ S ≤ 28, 1 ≤ M ≤ 19)

int U[3];     //user
int C[3]{0};  //current
using namespace std;
namespace _Name
{
    int a = 10;
}  

int CountDay(int);  // 변수 대입을 통한 초기화
int Check();
int calculateYear(void) {
    int result;
    int year = 1;
    while (1) {
        if ((year - E) % 15 == 0 && (year - S) % 28 == 0 && (year - M) % 19 == 0) {
            result = year;
            break;
        }
        year++;
    }

    return result;
}

int main(int argc, char const *argv[]) {
    for (int i = 0; i < 3; i++) {

        cin >> U[i];
    }

    // int result = CountDay(0);
    // cout << result << endl;
    for (int i = 0;; i++) {  // 계속 증가하면서 나머지 연산한 값과 비교하여 같다면
        if (i % 15 == U[0] && i % 28 == U[1] && i % 19 == U[2]) {
            cout << i << '\n';  // +1한 값을 출력
            break;
        }
    }
    return 0;
}

int Check() {
    if (U[0] == C[0] && U[1] == C[1] && U[2] == C[2]) {
        return 1;
    }
    return 0;
}
int CountDay(int year) {
    while (!Check()) {
        C[0]++;
        C[1]++;
        C[2]++;
        if (C[0] > 15) C[0] = 1;
        if (C[1] > 28) C[1] = 1;
        if (C[2] > 19) C[2] = 1;
        year++;
    }

    return year;
}