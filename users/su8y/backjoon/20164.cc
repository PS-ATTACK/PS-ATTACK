#include <iostream>
#include <queue>
using namespace std;

int n;

int countHolsu(const string &n);

vector<string> createNewSplit(string num) {
	vector<string> v;

	if (num.size() == 2) {
		int twosum = (num[0] - '0') + (num[1] - '0');
		v.push_back(to_string(twosum));
		return v;
	} else {
		for (int i = 1; i < num.size() -1; i++) {
			for (int j = i + 1; j < num.size(); j++) {
				int threeSum = stoi(num.substr(0, i)) + stoi(num.substr(i, j-i)) + stoi(num.substr(j, num.size() - j));
				v.push_back(to_string(threeSum));
			}
		}
		return v;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;

	int minimum = __INT_MAX__;
	int maximum = 0;

	queue<pair<string, int>> q;
	q.push({to_string(n), 0});

	while (!q.empty()) {
		auto [num, cnt] = q.front();
		q.pop();
		if (num.size() == 1) {
			minimum = min(minimum, cnt + (stoi(num) % 2));
			maximum = max(maximum, cnt + (stoi(num) % 2));
			continue;
		}
		int nCnt = countHolsu(num) + cnt;
		vector<string> newStrings = createNewSplit(num);
		for(auto &newNum: newStrings) {
			q.push({newNum, nCnt});
		}
	}
	cout << minimum << " " << maximum << endl;

	return 0;
}

int countHolsu(const string &n) {
	int res = 0;

	for (int i = 0; i < n.size(); i++)
		if ((n[i] - '0') % 2 != 0)
			res++;

	return res;
}
