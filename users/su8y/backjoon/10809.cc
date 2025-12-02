#include <stdio.h>

int main(){
    char S[101]={0,};
    int i, j, arr[26] = {0,};

    scanf("%s",S);

    for ( i = 'a'; i <= 'z'; i++){
        for ( j = 0; j < 100; j++){//j는 index자리 
            if(S[j]==i){
                arr[i-'a'] = j+1;// 0 번쨰에 1을 집어넣어야함.
                break;
            }
        }  
    }

    for (i = 0; i < 26; i++){
        printf("%d ",arr[i]-1);
    }
    
    return 0;
}