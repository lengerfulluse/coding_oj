#include<iostream>
using namespace std;
class A {
    public:
        A(int a) {
            e = a;
        }
        int e;
        void const_fun(int a) const;
};

void A::const_fun(int a) const {
    cout<<"I am const function, cannot change variable content"<<endl;
    e = a;
}
    
int main() {
    int d = 5;
    const int a = 4;
    int * const b = &d;
    const int * const c = &d;
    return 0;
}

