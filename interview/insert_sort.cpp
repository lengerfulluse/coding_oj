#include<iostream>
using namespace std;
void insert_sort(int* arr, int len);
void bi_insert_sort(int* arr, int len);

int main() {
    int a[10] = {5, 7, 2, 23, 43, 3, 34, 405, 7, 98};
    bi_insert_sort(a, 10);
    return 0;
}

void bi_insert_sort(int* arr, int len) {
    int i, j, move_pos, temp;
    int low=0, high, middle;
    for(i=1; i<len; ++i) {
        low = 0; 
        high = i-1;
        while(low < high) {
            middle = (low + high)/2;
            if (arr[middle] == arr[i]) {
                move_pos = middle+1;
                cout<<"equal pos: "<<move_pos<<endl;
                break;
            }
            else if(arr[middle] < arr[i]) {
                low = middle + 1;
            } else
                high = middle - 1;
        }
        if(low == high) {
            if(arr[low] > arr[i])
                move_pos = low;
            else
                move_pos = low  + 1;
        }else if(low > high) {
            move_pos = low;
        }
        cout<<"low:"<<low<<"\t"<<"high:"<<high<<endl;
        // move from the move pos to cur i
        temp = arr[i];
        for(j=i-1; j >= move_pos; --j) {
            arr[j+1] = arr[j];
        }
        arr[move_pos] = temp;
    }

    for(i=0; i<len; ++i) {
        cout<<arr[i]<<"\t";
    }
    cout<<endl;
}

void insert_sort(int* arr, int len) {
    int i, j, temp;
    for(i=1; i<len; ++i) {
        j = i-1;
        temp = arr[i];
        while(j >= 0 && temp < arr[j]) {
            arr[j+1] = arr[j];
            --j;
        }
        arr[++j] = temp;
    }
    for(i=0; i<len; ++i) {
        cout<<arr[i]<<"\t";
    }
    cout<<endl;
}

            
