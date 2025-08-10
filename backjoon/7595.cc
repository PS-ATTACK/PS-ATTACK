#include <iostream>
#include <sstream>
#include <string>
using namespace std;

const char STAR = '*';
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	stringstream output;
	while(true) {
		int n;
		cin >> n;
		if(n == 0) break;
		for (int i=1; i<=n; i++){
			for (int j=1; j<=i; j++){ 
				output << STAR;
			}
			output << '\n';
		}
	}
	cout << output.str();
	return 0;
}