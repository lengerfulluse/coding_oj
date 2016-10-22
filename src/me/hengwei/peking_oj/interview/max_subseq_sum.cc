#include<iostream>
#include<vector>
#include<cassert>
using namespace std;
int sum(int a[], int i, int j);
int max(int a, int b);
void dynamic_programming(int a[], int n);
void brute_force(int a[], int n);
void seq(int a[], int n);

int main() {
    int a[] = {-4, 3, 56, -15, 34, 0, -14, 4};
    dynamic_programming(a, 8);
    brute_force(a, 8);
    seq(a, 8);
    return 0;
}

void seq(int a[], int n) {
    int max = a[0];
    int begin = 0;
    int end = 0;
    int sum = 0;
    for(int i=0; i<n; i++) {
        sum += a[i];
        if(max < sum) {
            max = sum;
            end = i;
        }
        if(sum < 0) {
            begin = i+1;
            sum = 0;
            end = i+1;
        }
    }
    cout<<"begin:"<<begin<<"\t"<<"end:"<<end<<endl;
    cout<<"max:"<<max<<endl;
}
        
void brute_force(int a[], int n) {
    assert(n>0);
    int* b = new int[n];
    for(int i=0; i<n; i++) {
        b[i] = a[i];
        for(int j=i; j>=0; j--) {
            int temp = sum(a, j,i);
            b[i] = b[i] > temp ? b[i] : temp;
        }
    }
    int max = b[0];
    for(int i=1; i<n; i++) {
        max = max > b[i] ? max : b[i];
    }
    cout<<"max:"<<max<<endl;
}
        
                
void dynamic_programming(int a[], int n) {
    int* b = new int[n];
    assert(n>0);
    b[0] = a[0];
    /* O(n) time complexity */
    for(int i=1; i<n; i++) {
        b[i] = max(b[i-1]+a[i], a[i]);
    }
    int max = b[0];
    for(int i=1; i<n; i++) {
        if(max < b[i]) {
            max = b[i];
        }
    }
    cout<<"max:"<<max<<endl;
}

int sum(int a[], int i, int j) {
    assert(i<=j);
    int sum = a[i];
    for(int temp=i+1; temp<= j; temp++) {
        sum += a[temp];
    }
    return sum;
}
        
int max(int a, int b) {
    return a > b ? a : b;
}
