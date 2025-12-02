#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	stringstream output;
	cin >> t;
	while(t--) {
		string str1, str2; 
		cin >> str1 >> str2;
		int count = 0;
		for (int i = 0; i < str1.size(); i++) {
			if(str1[i] != str2[i]) count++;
		}
		output << "Hamming distance is " + to_string(count) + ".\n";
	}

	cout << output.str() << endl;

	return 0;
}