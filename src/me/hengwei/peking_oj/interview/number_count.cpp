#include<iostream>
#include<cassert>
using namespace std;
void num_count(int a[], int len);
int main() {
    int a[10] = {1, 2, 3, 2, 1, 5, 6, 3, 3, 5};
    num_count(a, 10);
    return 0;
}

/* implementation the number count program, which given a array of n size,
 * with all its value range from 1 to n, and please statistic all numbers'
 * frequency with O(n) time complexity and O(1) space complexity.
 */
void num_count(int a[], int len) {
    for(int loop=0; loop<len; loop++) {
        a[a[loop]%10] += 10;
    }
    for(int loop=0; loop<len; loop++) {
        cout<<loop<<":"<<a[loop]/10<<endl;
    }
}
