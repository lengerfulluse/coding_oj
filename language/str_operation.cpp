#include<iostream>
#include<cassert>
using namespace std;
int str_cmp(char* str1, char* str2);
void mem_cpy(void* dest, const void* src, size_t n);
int main() {
    char* str1 = "hello";
    char* str2 = "world";
    cout<<str_cmp(str1,str2);
    return 0;
}

void mem_cpy(void* dest, const void* src, size_t n) {
    assert(dest != NULL && src != NULL);
    if(dest == src) {
        return;
    }
    register char* d;
    register char* s;
    if(dest < src) {
        d = dest;
        s = src;
        while(n >= 4) {
            *d++ = *s++;
            *d++ = *s++;
            *d++ = *s++;
            *d++ = *s++;
            n -= 4;
        }
        while(n >0) {
            *d++ = *s++;
            n--;
        }
    }
    if(dest > src) {
        d = dest + n-1;
        s = src + n-1;
        while(n >= 4) {
            *d-- = *s--;
            *d-- = *s--;
            *d-- = *s--;
            *d-- = *s--;
            n -= 4;
        }
        while(n>0) {
            *d-- = *s--;
            n--;
        }
   }
}
            

int str_cmp(char* str1, char* str2) {
    /* NULL pointer validate */
    assert(str1 != NULL&& str2 != NULL);
    /* two things here:
     * 1. original passed argument pointer directly.
     * 2. str1 != '\0' equals str1 != '\0' && str2 != '\0' 
     */
    while(*str1 == *str2 && *str1 != '\0') {
        str1++;
        str2++;
    }
    return *str1 - *str2;
}


