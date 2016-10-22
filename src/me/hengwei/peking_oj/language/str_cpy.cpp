#include<iostream>
#include<cassert>
using namespace std;
char* strcpy(char* dest, const char* src);
int main() {
    char* dest = new char[20];
    char* src = "hello, world";
    strcpy(dest, src);
    while(*dest != '\0') {
        cout<<*dest<<"\t";
        dest++;
    }
    cout<<endl;
    return 0;
}

char* strcpy(char* dest, const char* src)
{
    assert(dest!=NULL && src!=NULL);
    char* ret = dest;
    while((*dest++ = *src++) != '\0');
    return ret;
}
