#include<iostream>
using namespace std;
class A {
public:
    A(){
        int a = 45;
        cout<<"construct a "<<a<<endl;
    }
    virtual ~A(){
        cout<<"destruct a"<<endl;
    }
       
};

int main() {
    A a;
    cout<<"size of empty A is: "<<sizeof(a)<<endl;
    return 0;
}
