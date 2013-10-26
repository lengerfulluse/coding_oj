#include<iostream>
using namespace std;
class A {
    public:
        const static int a;
        const static int b = 4;
        static int c;
        void print();
        
        static void print_() {
            cout<<"I am static"<<endl;
            /* Compile Error:
             * cannot invoke non static member variable or function
             */
            print();
        }
};

const int A::a = 3;
int A::c = 5;
void A::print() {
    cout<<"I am non static" <<endl;
}

int main() {
    return 0;
}
