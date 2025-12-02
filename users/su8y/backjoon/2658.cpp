// #include <bits/stdc++.h>
#include <iostream>
#include <map>
#include <string>
#include <set>
#include <utility>
#define SIZE 10
#include <unordered_set>
using namespace std;
typedef pair<int, int> pii;

pii ans[3];
int arr[SIZE][SIZE];
void rotate(){
    int tmp[10][10];
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++)
            tmp[i][j] = arr[i][j];
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++)
            arr[i][j] = tmp[SIZE-1-j][i];
            // arr[i][j] = tmp[j][SIZE-1-i];
}
void printMap(){
    for(int i =0;i<SIZE;i++){
        for(int j=0;j<SIZE;j++){
            printf("%d",arr[i][j]);
        }
        cout<< endl;
    }
}
bool style1(){
    int x = -1 ,y = -1;
    for(int i =0; i <SIZE;i++){
        for(int j = 0;j<SIZE;j++){
            if(arr[i][j] == 1){
                x = j; y = i;
                break;
            }
            if(x !=  -1 && y != -1) break;
        }
    }
    if(x !=  -1 && y != -1) return false; 

    ans[0] = { y, x };
    int tmp[10][10];
    memset(tmp,0,sizeof(tmp));

    for(int i =0; i < 10; i++){
        for(int j = x - i; j < 10; j++){
            tmp[i][j] = 1;
        }

    }

    for(int i =0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            printf("%d" , tmp[i][j]);
        }

    }

    return true;
}
int main(){
    for(int i =0;i<SIZE;i++){
        for(int j=0;j<SIZE;j++){
            scanf(" %1d",&arr[i][j]);
        }
    }
   style1(); 
   return 0;
}