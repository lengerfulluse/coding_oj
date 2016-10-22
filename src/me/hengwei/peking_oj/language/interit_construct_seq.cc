#include<iostream>
using namespace std;
/* for class in c++, default is all private, unless explicitly declare */ 
class Base {
    public:
    Base();
    ~Base();
    /* for vitual function, it must define in class */
    virtual void init() {
    cout<<"init Base"<<endl;
    }
}; /* declare a class, we need also a semicolon at the end */
Base::Base() {
    init();
}

Base::~Base() {
    cout<<"release Base"<<endl;
}
class InheritBase: Base {
    public:
    InheritBase();
    ~InheritBase();
    virtual void init() {
    cout<<"init inhreitbase"<<endl;
    }
};
InheritBase::InheritBase() {
    init();
}

InheritBase::~InheritBase() {
    cout<<"release InheritBase"<<endl;
}

int main() {
    /* two method declare a class variable, such as:
     * 1. InheritBase base;  local stack.
     * 2. InheritBase *base = new InheritBase(); construct in heap
     * and the former is destructed automatically. but the later, need 
     * explictly detele.
     */
    InheritBase  base;
    return 0;
}
