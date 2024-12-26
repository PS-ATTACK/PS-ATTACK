#include <iostream>
#include <algorithm>
using namespace std;
int res[100][100] = { 0 };
void squareCount(int x,int y,int i, int j){
    for(int z = x; z < i; z++){
        for(int f = y ; f < j; f++){
            res[z][f]++;
        }
    }
}
int main(){
    int btx,bty,tpx,tpy;
    int cnt= 0;
    for(int i=0;i<4;i++){
        cin >> btx >> bty >> tpx >> tpy;
        squareCount(btx,bty,tpx,tpy);
    }
    for(int i =0; i < 100; i++){
        for(int j =0;j<100;j++){
            if(res[i][j]){
                cnt++;
            } 
        }
    }
    printf("%d",cnt);

    return 0;
}