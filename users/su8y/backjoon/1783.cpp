#include <iostream>
using namespace std;
int main(void){
    static int result=0;
    int n,m;
    scanf("%d %d",&n,&m);
    if(n==0){
        cout << 0 << endl;
    } else if(n == 1){
        cout << 1 << endl;
    } else if(n == 2){
        4 < (m+1)/2 ? cout << 4: cout << (m+1)/2;
        return 0;
    } else {
        if(m == 4){
            cout << m << endl; return 0;
        // 6보다 아래일때는 4칸 아니면 더 움직이지 못함
        } else if(m < 7){
            cout << min(4,M)
            return 0;
        }
        cout << m -2;
    }
    return 0;
}