#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

int n = 0;
int arr[101] = { 0 };
int check[101] = { 0 };
vector<int> res;

void dfs(int current,int start) {
    if(check[current] == 0){
        check[current] = start;
        dfs(arr[current],start);
    }
    else if(current == start){
        res.push_back(start);
        return;
    }
}

int main() {
	cin >> n;

	for (int i = 1; i <= n; i++)
		cin >> arr[i];
	
	for (int i = 1; i <= n; i++) {
		memset(check, 0, sizeof(check));
		dfs(i, i);
	}
    printf("\n");
	cout << res.size() << endl;
	for (int i = 0; i < res.size(); i++)
		cout << res[i] << endl;
}