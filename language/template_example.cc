#include<iostream>
using namespace std;

template<typename T>
T imax(T a, T b) {
    return a>b ? a:b;
 }

int main() {
    cout<<"5,"<<"0 "<<endl;
    cout<<imax(5,0)<<endl;
    return 0;
}

