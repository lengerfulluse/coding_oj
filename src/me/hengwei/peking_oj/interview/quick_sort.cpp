#include<iostream>
using namespace std;
int bi_search(int* arr, int len, int x);
void quick_sort(int* arr, int start, int end);
int partition(int* arr, int start, int end);

int main() {
    int arr[10] = {1, 22, 13, 4, 36, 7, 8, 29, 16, 16};
    int i;
    quick_sort(arr, 0, 9);
    for(i=0; i<10; i++) {
        cout<<arr[i]<<"\t";
    }
    cout<<endl;
    return 0;
}
void quick_sort(int* arr, int start, int end) {
    if(start >= end)
        return;
    int pivot = partition(arr, start, end);
    quick_sort(arr, start, pivot-1);
    quick_sort(arr, pivot+1, end);
}

int partition(int* arr, int start, int end) {
    int pivot = arr[start];
    int pivot_pos = start;
    int i,j,temp;
    for(i=start+1; i<=end; ++i) {
        if(arr[i] < pivot) {
            temp = arr[pivot_pos+1];
            arr[pivot_pos+1] = arr[i];
            arr[i] = temp;
            pivot_pos++;
        }
     }
     arr[start] = arr[pivot_pos];
     arr[pivot_pos] = pivot;
     return pivot_pos;
}

int bi_search(int* arr, int len, int x) {
    int low, high, middle;
    low = 0;
    high = len - 1;
    while(low <= high) {
        middle = (low + high)/2;
        if(arr[middle] == x) {
            return middle;
        } else if (arr[middle] < x) {
            low = middle + 1;
        }else 
            high = middle - 1;
    }
    return -1;
}
