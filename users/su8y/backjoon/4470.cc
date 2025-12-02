#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int n;
int main() {
	cin >> n;
	stringstream output;
	cin.ignore();

	for (int i = 1; i <= n; i++) {
		string str;
		getline(cin, str);
		output << i << ". " << str << endl;
	}
	cout << output.str() << endl;

	return 0;
}
