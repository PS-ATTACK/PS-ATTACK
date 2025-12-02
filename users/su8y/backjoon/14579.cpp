#include <iostream>
using namespace std;

int a, b;
int main() {
	// 코드 작성
	cin >> a >> b;
	long res = 1;
	for(int i=a;i<=b; i++) {
		int sum = 0;
		for(int j=1;j<=i;j++){
			sum += j;
		}
		res = (res * sum) % 14579;
	}
	cout << res << endl;
	
	return 0;
}