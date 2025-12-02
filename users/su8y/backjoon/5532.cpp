#include <iostream>
using namespace std;

int L;
int B, A;
int C, D;
int main() {
	cin >> L >> B >> A >> C >> D;

	int koreanDays = B / C;
	int mathDays = A / D;
	if (B % C != 0)
		koreanDays++;
	if (A % D != 0)
		mathDays++; 
	cout << L - max(koreanDays,  mathDays);

	return 0;
}
