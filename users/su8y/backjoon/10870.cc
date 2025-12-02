#include <iostream> 

using namespace std;
int arr[21] = {0,1,1};
int fib(int n ){
    if(n == 0) return arr[0];
    if(n == 1) return arr[1];
    for(int i = 3; i < n + 1; i++){
        arr[i] = arr[i-2] + arr[i-1];
    }
    return arr[n];
}
int main(){
    int n,res=0;
    scanf("%d",&n);
    res = fib(n);
    printf("%d\n",res);
}