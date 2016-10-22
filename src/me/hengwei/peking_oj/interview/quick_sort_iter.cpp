#include<iostream>
#include<stack>
#include<vector>
using namespace std;

void quick_sort(int a[], int start, int end);
void quick_sort_iter(int a[], int start, int end);
int partition(int a[], int start, int end);
void print_array(int a[], int len);
int main() {
    int a[] = {32, 5, 654, 35, 67, 8, 85, 1342};
    print_array(a, 8);
    quick_sort_iter(a, 0, 7);
    print_array(a, 8);
    return 0;
}

/* Just store the start and end pos, partition function is still
 * unchange. and this is the common thought for the convert recursive
 * to iterator implementation.
 */
void quick_sort_iter(int a[], int start, int end) {
    if(start >= end) {
        return;
    }
    /* put the  first partition into stack */
    int pivot_pos = partition(a, start, end); 
    stack< vector<int> > s_pivot;
    vector<int> iter_value;
    iter_value.push_back(start);
    iter_value.push_back(pivot_pos);
    iter_value.push_back(end);
    s_pivot.push(iter_value);

    while(!s_pivot.empty()) {
        iter_value = s_pivot.top();
        s_pivot.pop();
        if(iter_value[0] < (iter_value[1]-1)) {
            vector<int> left_iter;
            left_iter.push_back(iter_value[0]);
            left_iter.push_back(partition(a, iter_value[0], iter_value[1]-1));
            left_iter.push_back(iter_value[1] - 1);
            s_pivot.push(left_iter);
        }
        if((iter_value[1]+1) < iter_value[2]) {
            vector<int> right_iter;
            right_iter.push_back(iter_value[0]);
            right_iter.push_back(partition(a, iter_value[1]+1, iter_value[2]));
            right_iter.push_back(iter_value[2]);
            s_pivot.push(right_iter);
        }
    }
}

void quick_sort(int a[], int start, int end) {
    /* for the reverse, terminal condition is the key point */
    if(start >= end) {
        return;
    }
    int pivot = partition(a, start, end);
    quick_sort(a, start, pivot-1);
    quick_sort(a, pivot+1, end);
}

int partition(int a[], int start, int end) {
    int small = start;
    /* the first set as pivot and switch finally */
    int index = start+1;
    int pivot = a[start];
    while(index <= end) {
        if(a[index] < pivot) {
            small++;
            int temp = a[index];
            a[index] = a[small];
            a[small] = temp;
        }
        index++;
    }
    /* swap the final small with povit */
    a[start] = a[small];
    a[small] = pivot;
    return small;
}
void print_array(int a[], int len) {
    for(int i=0; i<len; i++) {
        cout<<a[i]<<"\t";
    }
    cout<<endl;
}
