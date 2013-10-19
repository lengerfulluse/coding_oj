#include<iostream>
# include<cassert>
#include<cstdlib>
using namespace std;
char* istrcpy(char* dest, const char* src);
int main() {
    char* src = "hello,world";
    char* dest = (char*) malloc(20*sizeof(char));
    istrcpy(dest, src);
    return 0;
}

char* istrcpy(char* dest, const char* src) {
    assert(dest != NULL && src != NULL);
    char* target = dest;
    while(*target++ = *src++);
    return target;
}
