#include <algorithm>
#include <iostream>
#include <vector>
// #define swap(x,y,t) ((t=y),(y=x),(x=t))
using namespace std;
int arr[1000001];
void quicksort( int start, int end) {
    if (start >= end) return;
    int pivot = arr[(start + end) / 2];
    int left = start;
    int right = end;
    int temp;
    while (left <= right) {
        while (arr[left] < pivot) left++;
        while (arr[right] > pivot) right--;
        if (left <= right) {
            swap(arr[left], arr[right]);
            left++;
            right--;
        }
    }
    quicksort( start, right);
    quicksort( left, end);
}

int main(void) {
    ios::sync_with_stdio(false);
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) cin >> arr[i];
    random_shuffle(arr, arr + n);
    quicksort( 0, n - 1);

    for (int i = 0; i < n; ++i) {
        printf("%d\n", arr[i]);
    }
    return 0;
}