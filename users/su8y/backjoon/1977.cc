#include <cmath>
#include <iostream>

using namespace std;

int main() {
    int start, end;
    int sqrt_count = 0;
    int sqrt_sum = 0;
    int sqrt_min = 0;
    cin >> start >> end;
    //start 가 end 보다 커서 오류가 날 경우
    if (start > end) {
        return -1;
    }
    sqrt_min = end + 1;
    for (int i = start; i <= end; ++i) {
        if (sqrt(i) == (int)sqrt(i)) {
            sqrt_count++;
            sqrt_sum += i;
            if (sqrt_min > i) {
                sqrt_min = i;
            }
        }
    }
    if (sqrt_count < 1) {
        sqrt_sum = -1;
        cout << sqrt_sum << endl;
        return 0;
    } else
        cout << sqrt_sum << "\n"
             << sqrt_min << endl;

    return 0;
}