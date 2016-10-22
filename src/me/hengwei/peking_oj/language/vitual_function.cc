#include<iostream>
using namespace std;

/* a simple example show the difference between the dynamic binding
 * and static binding. And common function override is a static 
 * binding which aims to implement a common function in different 
 * class. However, the virtual function is just aimed at interface-like 
 * function. It implement the dynamic binding.
 */
class shape {
public:
    shape() { };
    virtual void draw() {
        cout<<"Draw shoap"<<endl;
    }
};

class rectangle: public shape {
public:
    rectangle() {};
    void draw() {
        cout<<"Draw rectangle"<<endl;
    }
};

class round: public shape {
public:
    round() {};
    void draw() {
        cout<<"Draw round"<<endl;
    }
};

int main() {
    shape* s;
    s = new rectangle();
    s->draw();

    s = new round();
    s->draw();
    return 0;
}
