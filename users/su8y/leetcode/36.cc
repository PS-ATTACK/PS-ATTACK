class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<char, int> hashMap;
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                char num = board[i][j];
                if (isdigit(num) && ++hashMap[num] == 2) {
                    cout << 1 << endl;
                    return false;
                }
            }
            hashMap.clear();
        }

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                char num = board[j][i];
                if (isdigit(num) && ++hashMap[num] == 2) {

                    cout << 2 << endl;
                    return false;
                }
            }
            hashMap.clear();
        }
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < 9; k++) {
                    int col = k / 3;
                    int row = k % 3;
                    char num = board[i*3 + col][j*3 + row];
                    if (isdigit(num) && ++hashMap[num] == 2) {
                        cout << 3 << endl;
                        return false;
                    }
                }
                hashMap.clear();
            }
        }
        return true;
    }
};