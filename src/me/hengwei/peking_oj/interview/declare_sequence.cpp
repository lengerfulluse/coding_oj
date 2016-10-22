#include<iostream>
using namespace std;
static int n = 1;
class A {
public:
    A(int n):z(n++), y(n++), x(++n) {
        cout<<"initialize: x"<<x<<" y "<<y<<" z "<<z<<endl;
    }
private:
    int x;
    int y;
    int z;
};

int main() {
    A a(1);  /* output x:2 y:2 z:3 */
    return 0;
}

/* the initialize sequence is corresponding to the sequence of 
 * class member declaration, but the initialize list followed by
 * construct function.
 */
