#include<iostream>
using namespace std;

int findAppearOnce(int *array, int len);
int main() {
    int a[] = {1, 1, 2, 2, 3, 3, 5};
    cout<<findAppearOnce(a, 7)<<endl;;
    return 0;
}

/* Question: there are 2N + 1 numbers, where all of them appear twice, except one,
 *           please find the one.
 * Solution:   XOR operator just give the solution.
 */

int findAppearOnce(int *array, int len){
    int result=0;
    for(int i=0;i<len;i++)
        result^=array[i];
    return result;
}
