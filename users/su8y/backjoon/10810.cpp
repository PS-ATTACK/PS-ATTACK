#include <iostream>

using namespace std;
int a[101], n, m;

int main() {
	cin >> n >> m;

	while (m--) {
		int s, e, x;
		cin >> s >> e >> x;
		for (int i = s; i <= e; i++)
			a[i] = x;
	}

	string s;
	for (int i = 1; i <= n; i++) {
		s += to_string(a[i]);
		if (i != n)
			s += " ";
	}
	cout << s << endl;
	return 0;
}
