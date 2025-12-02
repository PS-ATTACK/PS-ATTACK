#include <iostream>
#include <vector>

using namespace std;
struct Time{
    int hour;
    int min;
    int sec;
};
int timesum(Time t);
int main(){
    Time S,C;

    int now_sum, start_sum;

    scanf("%d:%d:%d",&C.hour,&C.min,&C.sec);
    scanf("%d:%d:%d",&S.hour,&S.min,&S.sec);

    now_sum = timesum(C);
    start_sum = timesum(S); 
    int temp = start_sum - now_sum;
    if(start_sum > now_sum){
        printf("%02d:%02d:%02d",temp/3600,temp%3600/60,temp% 60);
    }
    else{
        temp = 24*3600 + start_sum - now_sum;
        printf("%02d:%02d:%02d",temp/3600,temp%3600/60,temp% 60);
    }
    return 0;
}
int timesum(Time t){
    int sum = t.hour * 3600 + t.min * 60 + t.sec;
    return sum;
}
