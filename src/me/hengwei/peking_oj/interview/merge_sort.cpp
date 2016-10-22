#include<iostream>
using namespace std;
int* merge(int* arr_a, int a_len, int* arr_b, int b_len);
int* merge_sort(int* arr, int start, int end);

int main() {
    int arr[10] = {23, 4, 5, 2, 35, 21, 678, 345, 8, 7};
    int* a;
    int i;
    a = merge_sort(arr, 0, 9);
    for(i=0; i<10; ++i) {
        cout<<a[i]<<"\t";
    }
    cout<<endl;
    return 0;
}

int* merge_sort(int* arr, int start, int end) {
    //if only one element, construct array and return.
    if(start == end) {
        int* a = new int[1];
        a[0] = arr[start];
        return a;
    }
    int middle = (start+end)/2;
    return merge(merge_sort(arr, start, middle), middle-start+1,  merge_sort(arr, middle+1, end), end-middle);
}

int* merge(int* arr_a, int a_len, int* arr_b, int b_len) {
    cout<<"merge--len_a: "<<a_len<<"\tlen_b: "<<b_len<<endl;
    int i=0,j=0,cur_pos=0;
    int* result = new int[a_len+b_len];

    while(i<a_len && j<b_len) {
        while(i<a_len && arr_a[i] <= arr_b[j]) {
            result[cur_pos++] = arr_a[i++];
        }
        while(j<b_len && arr_b[j] < arr_a[i]) {
            result[cur_pos++] = arr_b[j++];
        }
    }
    if(i == a_len) {
        while(j<b_len) {
            result[cur_pos++] = arr_b[j++];
        }
    }
   if(j == b_len) {
        while(i<a_len) {
            result[cur_pos++] = arr_a[i++];
        }
   }
   return result;
}
