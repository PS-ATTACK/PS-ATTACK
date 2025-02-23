#include <bits/stdc++.h>

#define ll long long
#define FAST_IO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

#define pii pair<int, int>
#define pis pair<int, string>
#define pdd pair<double, double>
#define vvi vector<vector<int>>
#define vvc vector<vector<char>>

using namespace std;
int N, M, K;
unordered_set<string> combined_set;

/*
 * 각 정점(로봇 포함)을 정점간의 가중치를 구한다.
 *  정점간의가중치를구하려면 정점 총 11개에서 출발하는 11개로의 최단거리를 알아야 한다.
 * 각정점간의가중치를구하려면
 * 가중치를통하여MST알고리즘을사용한다.(크루스칼)
 *  1.가중치를 정렬
 *  2.각 정점을 가중치를 연결한다.
 *      2-1.가중치를연결하면서 Cycle 그래프가 되는지를 관찰한다.
 */

#define MAX_VALUE 999999
vvc graph;
vector<pii > vertex;
vvi cost;
vector<pair<int, pair<int, int>>> ordered_cost;
vector<int> root;

bool cmp(const pair<int, pair<int, int>> &a, const pair<int, pair<int, int>> &b) {
    return a.first < b.first;
}

int dirs[4][2] = {
        {0,  1},
        {0,  -1},
        {1,  0},
        {-1, 0},
};

bool is_valid(int y, int x) {
    return y >= 0 && y < N && x >= 0 && x < M;

}


int bfs_robot(pii robot, int end) {
    vector<vector<bool>> visited(N, vector<bool>(M, false));

    queue<pair<int, pii>> q;
    q.push({0, robot});
    visited[robot.first][robot.second] = true;

    while (!q.empty()) {
        int cost = q.front().first;
        pii f = q.front().second;
        q.pop();

        if (f == vertex[end]) return cost;

        for (int i = 0; i < 4; i++) {
            int ny = f.first + dirs[i][0];
            int nx = f.second + dirs[i][1];
            if (is_valid(ny, nx) && graph[ny][nx] != 'x' && visited[ny][nx] == false) {
                q.push({cost + 1, {ny, nx}});
                visited[ny][nx] = true;
            }
        }
    }
    return -1;
}

int bfs(int start, int end) {
    vector<vector<bool>> visited(N, vector<bool>(M, false));

    if (cost[start][end] != -1) return cost[start][end];
    queue<pair<int, pii>> q;
    q.push({0, vertex[start]});
    visited[vertex[start].first][vertex[start].second] = true;

    while (!q.empty()) {
        int cost = q.front().first;
        pii f = q.front().second;
        q.pop();

        if (f == vertex[end]) return cost;

        for (int i = 0; i < 4; i++) {
            int ny = f.first + dirs[i][0];
            int nx = f.second + dirs[i][1];
            if (is_valid(ny, nx) && graph[ny][nx] != 'x' && visited[ny][nx] == false) {
                q.push({cost + 1, {ny, nx}});
                visited[ny][nx] = true;
            }
        }
    }
    return -1;
}

int m_find(int x) {
    if (root[x] == x) return x;

    return root[x] = m_find(root[x]);
}

void m_union(int a, int b) {
    a = m_find(a);
    b = m_find(b);

    if (a == b) return;
    if (a < b) root[b] = a;
    else root[a] = b;
}

vector<bool> visited;

int dfs(int x, int depth, int len) {
    int ret = 9999999;
    if (depth >= len) {
        return 0;
    }

    for (int i = 0; i < len; i++) {
        if (i == x || visited[i]) continue;
        if(cost[x][i] == -1) continue;
        visited[i] = true;
        ret = min(ret,
                  dfs(i, depth + 1, len) + cost[x][i]);
        visited[i] = false;
    }
    return ret;
}

int main() {
    FAST_IO
    while (true) {
        cin >> M >> N; // x y
        if (N == 0 && M == 0) break;

        graph.resize(N, vector<char>(M, '.'));

        int vertexCount = 0, idx_robot = -1;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                cin >> graph[i][j];
                if (graph[i][j] == '*' || graph[i][j] ==  'o') { // robot 포함 더러운 타일에 대한 정점 정보 저장
                    if (graph[i][j] == 'o')idx_robot = vertexCount;
                    vertexCount++;
                    vertex.emplace_back(i, j);
                }
            }
        }

        cost.resize(vertexCount, vector<int>(vertexCount, -1));
        for (int i = 0; i < vertexCount; i++) {
            for (int j = i + 1; j < vertexCount; j++) {
                if (i == j || cost[i][j] != -1) continue;

                int resultCost = bfs(i, j);
                if (resultCost <= 0) continue;
                cost[i][j] = cost[j][i] = resultCost;
                ordered_cost.push_back({resultCost, {i, j}});
                ordered_cost.push_back({resultCost, {j, i}});

            }
        }
//        std::sort(ordered_cost.begin(), ordered_cost.end(), cmp);
        visited.resize(vertexCount);
        std::fill(visited.begin(), visited.end(), false);

        visited[idx_robot] = true;
        int res =dfs(idx_robot, 1, vertexCount);
            if(res== 9999999){
                cout << "-1\n";
            }else cout << res  << endl;


        ordered_cost.clear();
        graph.clear();
        cost.clear();
        vertex.clear();
    }


    return 0;
}


