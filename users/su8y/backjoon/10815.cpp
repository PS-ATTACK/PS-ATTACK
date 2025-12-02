//2021-10-29
#include <iostream>
#include <algorithm>
#include <vector>

// int *arr1;
using namespace std;
void bubblesort(int *arr, int size);
void quicksort(int *arr,int start, int end);
int main(void){
    int N,M;
    cin >> N;
    int *arr1 = (int*)malloc(sizeof(int)*N);
    for(int i = 0; i < N; i++){
        cin >> arr1[i];
    }
    cin >> M;
    int *arr2 = (int*)malloc(sizeof(int)*M);
    for(int i = 0; i < M; i++){
        cin >> arr2[i];
    }
    int *tmpArr = (int*)malloc(sizeof(int)*M);
    quicksort(arr1,0,N - 1);//끝 인덱스를 보내줌
    //sort(arr1,arr1+N);


    for(int i=0;i<M;i++){
        int left = 0; int right = N - 1;
        while(left <= right){
            int mid = (left + right) / 2;
            if(arr1[mid] == arr2[i]){
                tmpArr[i] = 1;
            }
            if(arr1[mid] < arr2[i])
                left = mid + 1;
            else
                right = mid - 1;
        }
    }
    for(int i=0;i<M;i++){
        cout << tmpArr[i] << " ";
    }

}
void quicksort(int *arr1,int start,int end){
    if(start >= end) return;
    int pivot = start;
    int left = start + 1, right = end , temp;
    while(left <= right){
        while(left <= end && arr1[left] <= arr1[pivot]){
            left++;
        }
        while(right > start && arr1[right] >= arr1[pivot]){
            right--;
        }
        if(left > right){
            temp = arr1[right];
            arr1[right] = arr1[pivot];
            arr1[pivot] = temp;
        }
        else{
            temp = arr1[right]; 
            arr1[right] = arr1[left];
            arr1[left] = temp;
        }
    }
    quicksort(arr1,start,right -1);
    quicksort(arr1,right+1,end);
}
//버블소트는 시간초과임. 500000 * 500000 = 50,000,000,000 > 5백억번에 수행으로 500초가 걸린다 .이럴때 N(logN)의 기법이 필요하다.
void bubblesort(int *arr, int size){
    int temp;
    for(int i=0;i<size-1;i++){
        for(int j=0;j<size-(i+1);j++){
            if(arr[j]> arr[j+1]){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}