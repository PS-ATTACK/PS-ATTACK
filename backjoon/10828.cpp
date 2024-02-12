#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

class Stack{
    public:
    int *arr;
    int top = -1;
    int ptr = -1;
    Stack(int n){
        this->arr = (int*)malloc(sizeof(int) * n);
        this->ptr = 0 ;
    }
    void push(int n){
        this->arr[ptr] = n;
        this->ptr++;
    }
    int size(int n){
        return ptr < 0 ? 0 : this->ptr;
    }
    int _top(){
        if(empty() == 1) return -1;
        else
            return this->arr[ptr-1];
        return 0;
    }
    int empty(){
        return ptr <= 0 ? 1 : 0; 
    }
    void pop(){
        if(ptr <= 0){
            cout << -1 << endl;
        }
        else {
            cout << _top() << endl;
            this->arr[ptr] = 0;
            this->ptr--;
        }
    }
};
int main(){
    int n;
    int tmp;
    string str;
    scanf("%d",&n);
    Stack st(n);
    for(int i=0;i<n;i++){
        cin >> str;
        if(str == "push"){
            scanf("%d",&tmp);
            st.push(tmp);
        }
        if(str == "top"){
            cout << st._top() << endl;
        }
        if(str == "size"){
            cout << st.ptr << endl; 

        }
        if(str == "empty"){
            cout << st.empty() << endl;

        }
        if(str == "pop"){
            st.pop();
        }
    }
    return 0;
}