#include<iostream>
#include<cstring>
#include<cassert>
#include<bitset>
typedef unsigned char BYTE;
using namespace std;
void bitset_sort(int a[], int len);
void bitset_sort_v2(int a[], int len);
int main() {
    int a[5] = {2, 4, 1, 6, 3};
    bitset_sort_v2(a, 5);
    return 0;
}

void bitset_sort_v2(int a[], int len)
{
    bitset<8> sort;
    assert(a != NULL);
    for(int i=0; i<len; i++) {
        sort[a[i]] = 1;
    }
    for(int i=0; i<8; i++) {
        if(sort[i] == 1) {
            cout<<i<<"\t";
        }
    }
    cout<<endl;
}

void bitset_sort(int a[], int len) {
    assert(a != NULL);
    BYTE *b = new BYTE();
    memset(b, 0, sizeof(BYTE));
    for(int i=0; i<len; i++) {
        *b = *(b+a[i]/8) | 0x01<<a[i]%8;
    }
    
    int index = 0;
    while(index < 8) {
        /* remember that, you need the int conversion process, when
         * use the equal condition
         */
        if(int(*b >> index & 0x01) == 1) {
            cout<<index<<"\t";
        }
        index++;
    }
    cout<<endl;
}
