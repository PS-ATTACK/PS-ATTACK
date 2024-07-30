#include <bits/stdc++.h>

#define ll long long
#define FAST_IO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

#define pii pair<int, int>
#define pis pair<int, string>
#define pdd pair<double, double>
#define vvi vector<vector<int>>

using namespace std;
int N, K, L;
priority_queue<int, vector<int>, greater<int>> min_heap; // 최소 힙
priority_queue<int> max_heap; // 최대 힙


int main() {
    FAST_IO;
    cin >> N;

    int tmp;
    for (int i = 0; i < N; i++) {
        cin >> tmp;
        if (i == 0 || max_heap.top() >= tmp) {
            max_heap.emplace(tmp);
        } else {
            min_heap.emplace(tmp);
        }

        if (min_heap.size() + 1 < max_heap.size()) {
            min_heap.emplace(max_heap.top());
            max_heap.pop();
        } else if (min_heap.size() > max_heap.size()) {
            max_heap.emplace(min_heap.top());
            min_heap.pop();

        }
        if ((i + 1) % 2 == 0) {
            cout << min(max_heap.top(), min_heap.top());
        } else {
            cout << max_heap.top();
        }
        cout << "\n";
    }
    return 0;
}
