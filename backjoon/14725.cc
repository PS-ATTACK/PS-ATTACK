#include <bits/stdc++.h>

#define pint pair<int, int>
#define vvi vector<vector<int>>
#define FAST_IO cin.tie(NULL);cout.tie(NULL);ios::sync_with_stdio(false);

using namespace std;

int n;
const int MAX_VALUE = (2 * 1e8) + 1;

struct Node {
    Node *parent;
    vector<Node *> children;
    string value;

    bool operator<(Node b) {
        return value < b.value;
    }
};

void Connect(Node *src, Node *dst) {
    dst->children.push_back(src);
    src->parent = dst;
}

void dfs(Node *, int);

int main() {
    FAST_IO;
    Node *root = new Node;
    root->value = "";
    root->parent = NULL;

    cin >> n;
    int m;
    string str;
    for (int i = 0; i < n; i++) {
        cin >> m;
        Node *cur = root;

        for (int j = 0; j < m; j++) {
            cin >> str;
            vector<Node *> curChildren = cur->children;
            bool flag = false;

            // 자식에서 찾고 연결
            int len = curChildren.size();
            for (int k = 0; k < len; k++) {
                if (curChildren[k]->value == str) {
                    cur = curChildren[k];
                    flag = 1;
                    break;
                }
            }
            // 자식에서못찾았으면그냥해당위치에자식연결
            if (!flag) {
                Node *newNode = new Node;
                newNode->value = str;
                Connect(newNode, cur);
                cur = newNode;
            }

        }
    }


    dfs(root, 0);

    return 0;
}

void dfs(Node *root, int deps) {

    sort(root->children.begin(), root->children.end(), [](Node *a, Node *b) {
        return a->value < b->value;
    });
    if (deps > 0) {
        for (int i = 1; i < deps; i++) {
            cout << "--";
        }
        cout << root->value << "\n";
    }
    for (int i = 0; i < root->children.size(); i++) {
        dfs(root->children[i], deps + 1);
    }

    return;
}