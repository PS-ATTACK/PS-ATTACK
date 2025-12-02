#include <iostream> 

using namespace std;

int main(){
    int total;
    int price;
    int price_nine = 0;
    cin >> total;

    
    for(int i = 0; i<9; ++i){
        cin >> price; 
        price_nine += price;
    }
    //if(price_nine > total){
        //return 0;
    //}
    //else
    cout << total - price_nine << endl;
    return 0;
}