#include <iostream>
#include <vector>
#include <map>
#include <set>
// map && set 

using namespace std;

vector<int> dp;


void fib(int n){
    for(int i = 2; i<n;i++){
        dp.push_back(dp[i-2] + dp[i-1]);
    }
}

int main(void){
    int n = 0; int number = 0;

    dp.push_back(0);
    dp.push_back(1);
    fib(41);
    scanf("%d",&n);
    for(int i =0; i < n;i++){
        scanf("%d",&number);
        if(number < 41 && number >= 0){
                if(number ==0) printf("%d %d\n",1,0);
                else if(number ==1) printf("%d %d\n",0,1);
                else printf("%d %d\n",dp[number-1], dp[number]);
        }
        else return -1;

    }
    return 0;
}