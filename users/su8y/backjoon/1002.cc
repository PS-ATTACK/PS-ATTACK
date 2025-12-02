//#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>


using namespace std;

// a function to find intersection of two point
int solve(int,int,int,int,int,int);
double funcTwoPointDistance(int &x1,int &x2,int &y1, int &y2);
int main(){
    int n,x1,y1,r1,x2,y2,r2;
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
        cout << solve(x1,y1,r1,x2,y2,r2) << endl;
    }
    return 0;
}
double funcTwoPointDistance(int &x1,int &x2,int &y1, int &y2){
    return sqrt(pow(abs(x1 - x2),2) + pow(abs(y1 - y2),2));
}
int solve(int x1,int y1,int r1, int x2, int y2, int r2){
    double twoPointDistance = funcTwoPointDistance(x1,x2,y1,y2);

    // infinity
    if( r1 + r2 < twoPointDistance) return 0;
    else if(abs(r1 - r2) > twoPointDistance) return 0;
    else if(twoPointDistance == 0 && r1 == r2) return -1; 
    else if(twoPointDistance == (r1 + r2)) return 1; //외접하는경우 4 
    else if(abs(r1 - r2) == twoPointDistance) return 1;
    else return 2;
    // return answers;
}