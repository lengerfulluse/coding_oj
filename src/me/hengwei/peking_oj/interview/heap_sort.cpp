#include<iostream>
using namespace std;
void heap_sort(int* arr, int len);
void heapify(int* arr, int len, int );
int main() {
    int arr[10] = {23, 3, 5, 1, 435, 45, 75, 33, 356, 234};
    heap_sort(arr, 10);
    return 0;
}

void heap_sort(int* arr, int len) {
    int i=len/2 - 1;
    for(; i>=0; i--) {
        heapify(arr, len, i);
    }
    /* gradually eject the ele in the top of heap. */
    for(i=len-1; i>=0; i--) {
        cout<<arr[0]<<" ";
        arr[0] = arr[i];
        heapify(arr, i, 0);
    }
    cout<<endl;
}

/* the core process of heap sort */
void heapify(int* arr, int len, int top) {
    int left, right, small=top, temp;
    if(2*top < len) {
        left = top * 2;
        small = arr[small] > arr[left] ? left : small;
    }
    if(2*top + 1 < len) {
        right = top * 2  + 1;
        small = arr[small] > arr[right] ? right : small; 
    }
    if (small != top) {
        temp = arr[small];
        arr[small] = arr[top];
        arr[top] = temp;
        heapify(arr, len, small);
    }
}
