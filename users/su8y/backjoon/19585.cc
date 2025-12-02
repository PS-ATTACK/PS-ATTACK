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

struct TrieNode {
    TrieNode *childNode[26];
    int wordEndCount;

    TrieNode() {
        wordEndCount = 0;
        for (int i = 0; i < 26; i++) {
            childNode[i] = NULL;
        }
    }
};

TrieNode *insert_key(TrieNode *root, string &key) {
    TrieNode *curNode = root;

    int len = key.length();
    for (int i = 0; i < len; i++) {
        if (curNode->childNode[key[i] - 'a'] == NULL) {
            TrieNode *newNode = new TrieNode();
            curNode->childNode[key[i] - 'a'] = newNode;
        }
        curNode = curNode->childNode[key[i] - 'a'];
    }
    curNode->wordEndCount++;
    return root;
}

bool search_key(TrieNode *root, string &queryString) {
    TrieNode *curNode = root;
    int len = queryString.length();

    for (int i = 0; i < len; i++) {
        if (curNode->wordEndCount > 0 &&
            combined_set.find(queryString.substr(i, len)) != combined_set.end()) {
            return true;
        }
        if (curNode->childNode[queryString[i] - 'a'] == NULL) {

            return false;
        }
        curNode = curNode->childNode[queryString[i] - 'a'];
    }
//    return curNode != NULL && curNode->wordEndCount > 0;
    return false;
}


int main() {
    FAST_IO
    cin >> N >> M;
    vector<string> colors;
    vector<string> nicknames;
    string input;
    TrieNode *root = new TrieNode;

    for (int i = 0; i < N; ++i) {
        cin >> input;
        colors.emplace_back(input);
        insert_key(root, input);
    }
    for (int i = 0; i < M; ++i) {
        cin >> input;
        nicknames.emplace_back(input);
        combined_set.insert(input);
    }

//    for (int i = 0; i < N; i++) {
//        for (int j = 0; j < M; j++) {
//            string key = colors[i] + nicknames[j];
////            combined_set.insert(key);
////            insert_key(root, key);
//        }
//    }

    cin >> K;

    for (int i = 0; i < K; i++) {
        cin >> input;
        bool res = search_key(root, input);
//        bool res = combined_set.find(input) != combined_set.end();
        if (res) cout << "Yes\n";
        else cout << "No\n";
    }


//    free(root);
    return 0;
}
