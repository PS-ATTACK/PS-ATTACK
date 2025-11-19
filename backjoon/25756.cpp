#include <iomanip>
#include <iostream>
#include <sstream>
using namespace std;

int n, a[40'000];
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];

	stringstream ss;
	long double v = 0.0f;
	for (int i = 0; i < n; i++) {
		v = (1 - (1 - v) * (1 - a[i] / 100.0));
		ss << std::setprecision(7) << v *100<< endl;
	}
	cout << ss.str();

	return 0;
}
