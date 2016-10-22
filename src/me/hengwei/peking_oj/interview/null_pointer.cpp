#include<iostream>
using namespace std;
int main() {
    char* str = "Hello World";
    /* interview question in Alibaba internship 
     * when traverse string, we often get confused by
     * the pointer or value itself. And similar situation
     * when we use tree nodes or link nodes.
     */
    while(*str) {
        cout<<*str<<endl;
        str++;
    }
    return 0;
}
