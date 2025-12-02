#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

// 원소 a, b, c가 있을때 a, b를 포함하면 c도 포함이 될수있다.
int n;
int arr[367];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		int s, e;
		cin >> s >> e;
		for(int idx=s; idx <= e; idx++){
			arr[idx]++;
		}
	}

	
	int res =0;
	int lo=0;
	while(lo <= 365) {
		while(lo <= 365 && arr[lo] == 0) lo++; // 0이 아닌 위치 찾기
		int hi = lo;
		int h = 0;

		while(hi <= 365 && arr[hi] != 0) {
			h = max(h, arr[hi]);
			hi++;
		}
		
		res += (hi - lo) * h;
		lo = hi;
	}
	cout << res << endl;


	return 0;
}
