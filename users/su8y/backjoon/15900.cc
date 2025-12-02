#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>
using namespace std;

// 1=root, 모든 리프노드에 게임말 존재, parent로 이동,
// 아무것도 못고르는 사람이 lose
int n;
bool visited[500'001];
vector<int> edge[500'001];

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		edge[a].push_back(b);
		edge[b].push_back(a);
	}

	int res = 0;
	queue<pair<int, int>> q; // node, deps
	visited[1] = true;
	q.push({1, 0});

	while (!q.empty()) {
		auto cur = q.front();
		q.pop();

		bool leaf = true;
		for (int next : edge[cur.first]) {
			if (!visited[next]) {
				visited[next] = true;
				q.push({next, cur.second + 1});
				leaf = false;
			}
		}
		if(leaf) {
			res += cur.second;
		}
	}

	if (res % 2 == 0)
		cout << "No" << endl;
	else
		cout << "Yes" << endl;

	return 0;
}