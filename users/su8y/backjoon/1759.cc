//#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n,m;
char *chars;
char res[15];
string answers;
bool *isVowel;
bool visited[15];
void dfs(int depths,int num,int vowel,int consonant){
    if(depths == m){ //return 구문
        if(vowel >= 1 && consonant >= 2){
            for(int i = 0 ; i < m;i++){
                answers += res[i]; 
            }
            answers += "\n";
        }
        return;
    }

    for(int i = num;i <n;i++){ // 재귀함수 구문
        if(!visited[i]){
            visited[i] = true;
            res[depths] = chars[i];
            if (isVowel[i])
            {
                dfs(depths + 1,i,vowel + 1,consonant);
            }
            else{
            dfs(depths + 1,i,vowel,consonant + 1);

            }
            
            visited[i] = false;
        }
    }
}
void solve(){
    cin >> m >> n;    
    chars = new char[n];
    isVowel = new bool[n];
    for (size_t i = 0; i < n; i++)
    {
        cin >> chars[i];
    }
    
    sort(chars,chars+n); // 사전순 정렬 

    for (size_t i = 0; i < n; i++) // 자음 모음 판별
    {
        if(chars[i] == 'a' || chars[i] == 'e' || chars[i] == 'i' || chars[i] == 'o' || chars[i] == 'u'){
            isVowel[i] = true;
        }
    }
    
    dfs(0,0,0,0);
    cout << answers;
    
    delete chars;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //cout << "Hello World" << endl;
    solve();
    return 0;
}
