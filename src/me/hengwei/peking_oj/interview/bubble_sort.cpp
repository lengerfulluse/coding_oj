#include<iostream>
using namespace std;
void bubble_sort(int* arr, int len);
int main() {
    int arr[10] = {23, 4, 56, 46, 2, 1, 435, 12, 63, 0};
    bubble_sort(arr, 10);
    return 0;
}

void bubble_sort(int* arr, int len) {
    int i, j, temp;
    for(j=len-1; j>0; --j) {
        for(i=0; i<j; ++i) {
            if(arr[i] > arr[i+1]) {
                temp = arr[i+1];
                arr[i+1] = arr[i];
                arr[i] = temp;
            }
        }
    }

    for(i=0; i<len; ++i) {
        cout<<arr[i]<<"\t";
    }
    cout<<endl;
}
