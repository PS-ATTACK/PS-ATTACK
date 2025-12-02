#include <iostream>
using namespace std;

int n;
bool isSpecialNum(int number) {
	int sum = 0;

	int num = number;
	while(num > 0) {
		sum += num % 10;
		num /= 10;
	}
	
	return number % sum == 0;
}

int main() {
	cin >> n;
	
	int res = 0;
	for(int i =1;i<=n;i++) {
		if(isSpecialNum(i)) res++;
		
	}
	cout << res;
	return 0;
}