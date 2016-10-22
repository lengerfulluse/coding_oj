#include<iostream>
#include<string>
#include<cstdlib>
using namespace std;
const int MAX_LENGTH = 32;
int binary[MAX_LENGTH];

bool decimal_to_binary(char* str);
int main() {
    char str[20] = {"12334.345112"};
    cout<< decimal_to_binary(str)<<endl;
    return 0;
}

bool decimal_to_binary(char* str) {
    /* two ways to convert a char* to a string class:
     * 1. declare: string str_copy(str);
     * 2. cast: string(str);
     */
    string str_cpp(str);
    int dec_index = str_cpp.find('.');
    /* atoi function: parameter is const char* but string.
     * so for the atof function:
     * change  string to char*: str.c_str()
     */
    int int_pos=0, dec_pos=0;
    int int_part = atoi(str_cpp.substr(0, dec_index).c_str());
    double dec_part = atof(str_cpp.substr(dec_index, str_cpp.length()).c_str());
    while(int_part && int_pos < MAX_LENGTH) {
        int_part >>= 1;
        binary[int_pos++] = int_part% 2;
    }
    dec_pos = int_pos;

    while(dec_part && dec_pos < MAX_LENGTH) {
        dec_part *= 2;
        binary[dec_pos++] = dec_part > 1 ? 1 : 0;
        if(dec_part >= 1) {
            dec_part -= 1;
        }
    }
    if(dec_pos == MAX_LENGTH) {
        return false;
    }

    /* reverse the integer part */
    for(int i=0,j=int_pos-1; i<j; i++,j--) {
        binary[i] = binary[i] + binary[j];
        binary[j] = binary[i] - binary[j];
        binary[i] = binary[i] - binary[j];
    }
    /* print final conversion result */
    for(int i=0; i<dec_pos; i++) {
        cout<<binary[i] <<"\t";
    }
    cout<<endl;
    return true;
}
