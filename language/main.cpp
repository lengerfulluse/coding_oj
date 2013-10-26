#include <iostream>

using namespace std;

class A {

public:

    A();

    virtual ~A();

    virtual void fun();

};
A::A(){
    fun();
}
A::~A(){
    cout<<"~";
    fun();
}
void A::fun(){
    cout<<"A"<<endl;
}



class B: public A {
public:

    B();

    ~B();
    virtual void fun();

};
B::B(){
        fun();
}
B::~B(){
        cout<<"~";
        fun();
}
void B::fun(){
        cout<<"B"<<endl;
}

int main()
{
    cout << "Hello world!" << endl;

    A *p = new B;
    delete p;
    return 0;
}
