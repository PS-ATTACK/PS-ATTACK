#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int n, k;
vector<int> arr;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> k;
	
	for(int i=0; i<n; i++) {
		int score;
		cin >> score;
		arr.push_back(score);
	}
	
	sort(arr.begin(), arr.end(), [&](int a, int b){
			return a > b;
	});
	
	cout << arr[k - 1];
	
	
	return 0;
}