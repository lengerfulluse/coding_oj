#include<iostream>
#include<cassert>
using namespace std;
char* str_cpy(char* dest, const char* src);
int main() {
    char dest[] = "hello, world";
    char* src = "world";
    cout<<dest<<endl;
    cout<<str_cpy(dest, src)<<endl;
    return 0;
}

/* some important aspect need remember 
 * 1. src need declare as const type
 * 2. need the critical condition assert
 * 3. the final '\0' character 
 * 4. return destination address
 */
char* str_cpy(char* dest, const char* src) {
    assert(dest != NULL && src != NULL);
    char* address = dest;
    while((*dest++ = *src++) != '\0');
    return address;
}
