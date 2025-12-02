#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
// int arr[10] = {[0 ... 9] = 1 };
int n;
vector<int> broken;
int possible(int);
int length(int);
int solve1(){
    int result = 987654321;
    int similar = 0;
   for (int i = 0; i < 1000001; i++)
   {
       /* code */
       if(possible(i)){
           int click = abs(n -i);
           if(result > click){
               result = click;
               similar = i;
           }

       }
   }
   return result + length(similar);
    
}
int possible(int i){
    if( i == 0){
        if(find(broken.begin(),broken.end(),0) == broken.end()) return true;
        else return false;



    }
    while(i){
        if(find(broken.begin(),broken.end(),i % 10) != broken.end())
        i /= 10;
            return false;
    }
    return true;
}

int length(int a){
    if( a == 0) return 1;
    int result = 0;
    while( a != 0){
        a /= 10;
        result++;
    }
    return result;
}
int solve2(){
    return abs(n - 100);
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);


    int m; 
    cin >> n >> m;
    for (int i = 0; i < m; i++)    {
        int button;
        cin >> button;
        broken.push_back(button);
    }

    cout << min(solve1(), solve2()) << endl;
    
    return 0;
}