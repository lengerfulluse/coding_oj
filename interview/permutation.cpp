#include<iostream>
#include<assert.h>
using namespace std;

void full_permutation(const char* str);

int main() {
    char a[] = {"Hello, World!"};
    full_permutation(a);
    return 0;
}

void full_permutation(const char* str) {
    
