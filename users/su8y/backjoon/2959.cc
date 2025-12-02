#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> arr;
// 두개에서 작은거 큰거를 구하면 됌 
int main() {
	int n;
	
	for(int i=0;i<4;i++){
		cin >> n;
		arr.push_back(n);
	}
	sort(arr.begin(), arr.end());

	int x1 = min(arr[0], arr[1]);
	int y1 = min(arr[2], arr[3]);
	
	cout << x1 * y1 << endl;

	return 0;
}