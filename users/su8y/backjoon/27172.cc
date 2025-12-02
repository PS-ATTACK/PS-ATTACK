#include <iostream>
#include <vector>
#include <cstring>

#define endl "\n"


using namespace std;

const int MAX_N = 1000000;


int number_player_card[MAX_N + 1];
int score[MAX_N + 1];

// 10 ^ 5 * 10 ^ 5
int main() {
    ios::sync_with_stdio(false); // C++과 C의 동기화 비활성화
    cin.tie(NULL); // cin과 cout의 자동 플러시 비활성화


    vector<int> order_players;
    int n;
    cin >> n;

    memset(number_player_card, 0x00, sizeof(number_player_card));
    memset(score, 0x00, sizeof(score));

    /* input number_player_card card */
    for (int i = 0, tmp; i < n; ++i) {
        cin >> tmp;
        order_players.push_back(tmp);
        number_player_card[tmp] = 1;
    }

    for (const auto &item: order_players){
        for(int i = 2; item * i <= MAX_N; i++){
            /* check exist number_player_card*/
            bool is_exist = number_player_card[item * i] == 1;
            /* calc score */
            if(is_exist){
                score[item]++;
                score[item * i]--;
            }
        }
    }

    /* print result */
    for (const auto &item: order_players){
        cout << score[item] << " ";
    }
    cout << endl;


    return 0;
}


