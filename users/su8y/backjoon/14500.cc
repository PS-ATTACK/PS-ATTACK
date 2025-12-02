#include <algorithm>
#include <iostream>
#include <vector>

#define VVI vector<vector<int> >
using namespace std;
/*
	0,0 0,1
	1,0 1,1
*/
int n, m;
void input(int,int,VVI&);
int checkShape(int,int,VVI&);
void solve();
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	// cout << "Hello World" << endl;
	solve();

	return 0;
}
void input(int n, int m, VVI& map) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}
}
int checkShape(int y, int x, VVI& map) {
	int return_value = 0;

	if (y + 2 <= n - 1 && x + 1 <= m - 1) {
		return_value = max(return_value, map[y][x] + map[y][x + 1] + map[y + 1][x] + map[y + 2][x]);
	}
	if (x + 1 <= m - 1 && y + 2 <= n - 1) {
	  return_value = max(return_value, map[y][x] + map[y][x + 1] + map[y + 1][x + 1] + map[y + 2][x + 1]);
	}
	if (y + 1 <= n - 1 && x + 2 <= m - 1) {
	   return_value = max(return_value, map[y][x] + map[y + 1][x] + map[y][x + 1] + map[y][x + 2]);
	}
	if (y + 1 <= n - 1 && x + 2 <= m - 1) {
	   return_value = max(return_value, map[y][x] + map[y][x + 1] + map[y][x + 2] + map[y + 1][x + 2]);
	}
	if (y + 1 <= n - 1 && x + 1 <= m - 1) {
		return_value = max(return_value, map[y][x] + map[y + 1][x + 1] + map[y + 1][x] + map[y][x + 1]);
	}
	if (y + 2 <= n - 1 && x + 1 <= m - 1) {  // 6
		return_value = max(return_value, map[y][x] + map[y + 1][x] + map[y + 2][x] + map[y + 2][x + 1]);
	}
	if (y + 2 <= n - 1 && x - 1 >= 0) {  // 7
		return_value = max(return_value, map[y][x] + map[y + 1][x] + map[y + 2][x] + map[y + 2][x - 1]);
	}
	if (y + 1 <= n - 1 && x - 2 >= 0) {  // 8
		return_value = max(return_value, map[y][x] + map[y + 1][x] + map[y + 1][x - 1] + map[y + 1][x - 2]);
	}
	if (y + 1 <= n - 1 && x + 2 <= m - 1) {  // 9
		return_value = max(return_value, map[y][x] + map[y + 1][x] + map[y + 1][x + 1] + map[y + 1][x + 2]);
	}
	if (y + 3 <= n - 1) {
		return_value = max(return_value, map[y][x] + map[y + 1][x] + map[y + 2][x] + map[y + 3][x]);
	}
	if (x + 3 <= m - 1) {
		return_value = max(return_value, map[y][x] + map[y][x + 1] + map[y][x + 2] + map[y][x + 3]);
	}
	if (y + 2 <= n - 1 && x + 1 <= m - 1) {  // 11
		return_value = max(return_value, map[y][x] + map[y + 1][x] + map[y + 1][x + 1] + map[y + 2][x + 1]);
	}
	if (y + 2 <= n - 1 && x - 1 >= 0) {  // 12
		return_value = max(return_value, map[y][x] + map[y + 1][x] + map[y + 1][x - 1] + map[y + 2][x - 1]);
	}
	if (y + 1 <= n - 1 && x - 2 >= 0) {  // 13
		return_value = max(return_value, map[y][x] + map[y][x - 1] + map[y + 1][x - 1] + map[y + 1][x - 2]);
	}
	if (y + 1 <= n - 1 && x + 2 <= m - 1) {  // 13
		return_value = max(return_value, map[y][x] + map[y][x + 1] + map[y + 1][x + 1] + map[y + 1][x + 2]);
	}
	if (y + 1 <= n - 1 && x + 1 <= m - 1 && x - 1 >= 0) {
		return_value = max(return_value, map[y][x] + map[y + 1][x] + map[y + 1][x + 1] + map[y + 1][x - 1]);
	}//16
	if (y - 1 >= 0 && x + 1 <= m - 1 && x - 1 >= 0) {
		return_value = max(return_value, map[y][x] + map[y - 1][x] + map[y - 1][x + 1] + map[y - 1][x - 1]);
	}
	if (x + 1 <= m - 1 && y + 1 <= n - 1 && y - 1 >= 0) {
		return_value = max(return_value, map[y][x] + map[y][x+1] + map[y - 1][x + 1] + map[y + 1][x + 1]);
	}
	if (x - 1 >= 0 && y + 1 <= n - 1 && y - 1 >= 0) {
		return_value = max(return_value, map[y][x] + map[y][x-1] + map[y - 1][x - 1] + map[y + 1][x - 1]);
	}

	return return_value;

}
void solve() {
	cin >> n;
	cin >> m;

	int maxNumber;
	VVI map(n, vector<int>(m, 0));
	input(n, m, map);
	for (int i = 0; i < n; i++)  // y 축
	{
		for (int j = 0; j < m; j++)  // x축
		{
			maxNumber = max(maxNumber,(checkShape(i, j, map)));
		}
	}
   cout << maxNumber << endl; 
//    cout << map[0][4] + map[1][4] + map[2][4] + map[3][4] << endl;
//     for (int i = 0; i < n; i++)  // y 축
//     {
//         for (int j = 0; j < m; j++)  // x축
//         {
//             cout << map[i][j] << " ";
//         }
//         cout << endl;
//     }
   
}
