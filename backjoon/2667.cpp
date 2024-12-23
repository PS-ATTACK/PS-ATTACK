#include <iostream>
#include <vector>
#include <algorithm>

int map[25][25];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int N;
int check[25][25] = {0,};
int room; // 방개수 세는 변수
std::vector<int> checkroom;

void dfs(int x, int y, int cnt);
void quicksort(std::vector<int> arr,int start, int end);
int main() {
    int cnt = 0;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%1d", &map[i][j]);
        }
    }  //입력
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (map[i][j] == 1 && check[i][j] == 0) {
                room = 0;
                dfs(i, j, ++cnt);
                checkroom.push_back(room);
            }
        }
    }

    printf("%d\n", cnt);
    // quicksort(checkroom,0,checkroom.size());
    sort(checkroom.begin(),checkroom.end());
    for(int i =0; i<checkroom.size();i++){
        printf("%d\n",checkroom[i]);
    }
}
void dfs(int x, int y, int cnt) {
    room++;
    check[x][y] = 1;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (0 <= nx && nx < N && 0 <= ny && ny < N) {
            if (map[nx][ny] == 1 && check[nx][ny] == 0)
                dfs(nx, ny, cnt);
        }
    }
}
void quicksort(std::vector<int> arr,int start, int end){
    if(start >= end) return;
    int pivot = start;
    int left = start + 1;
    int right = end;
    int temp;
    while(left < right){
        while(left < end && arr[left] >= arr[pivot]){
            left++;
        }
        while(right >= start && arr[right] <= arr[pivot]){
            right--;
        }
        if(left > right){
            temp = arr[pivot];
            arr[pivot] = arr[right];
            arr[right] = temp;
        }
        else{
            temp = arr[right];
            arr[right] = arr[left];
            arr[left] = temp;
        }
    }
    quicksort(arr,start,right-1);
    quicksort(arr,right+1,end);

}