#include<iostream>
using namespace std;

class A {
public:
    void print(int a);
};
void A::print(int a) {
    cout<<"class a print"<<endl;
}

class B: public A {
public:
    void print(int a, double b);
};

void B::print(int a, double b) {
    cout<<"class B print"<<endl;
}

int main() {
    B* b = new B();
    b->print(2); /* Compile Error */
    b->print(1, 3); /* Execute B print */
    b->print(1, 2.45); /* Execute B print */
    return 0;
}

/* note:
 *      as long as derived class has the same name as the base class 
 *      and it's not virtual, when we declare the Derived class to invoke
 *      the function, it will always invoke the derived function. Except that
 *      there is no the same name function.
 */
