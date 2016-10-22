#include<iostream>
#include<cassert>
using namespace std;
const int max_len = 100;

int continue_max_str(char* outputstr, char* inputstr);
int main() {
    char* str = "abcd12345ed125ss123456789";
    char out[max_len];
    cout<<"length: "<<continue_max_str(out,str)<<" is: "<<out<<endl;
    return 0;
}

/* be aware of two issues:
 * 1. max_length and max_index variables.
 * 2. current length and index, also the flag to enter 
 *    the digitals
 */
int continue_max_str(char* outputstr, char* inputstr) {
    int max_length = 0, cur_length = 0;
    char* max_index=NULL, *cur_index=NULL;
    bool flag = false;
    while(*inputstr) {
        if(*inputstr <= '9' && *inputstr >= '0'){
            if(flag == false) {
                flag = true;
                if(cur_length > max_length) {
                    max_length = cur_length;
                    max_index = cur_index;
                }
                /* reset the current length */
                cur_length = 0;
                cur_index = inputstr;
            }
            cur_length++;
        } else {
            /* we can reset the current and compare the max here */
            flag = false;
        } 
        inputstr++;
    }
    if(max_length < cur_length) {
        while(cur_length) {
            *outputstr++ = *cur_index++;
            cur_length--;
        }
        *outputstr = '\0';
    } else {
        while(max_length) {
            *outputstr++ = *max_index++;
            max_length--;
        }
        *outputstr = '\0';
    }
    return max_length > cur_length ? max_length : cur_length;
}
            
            
        
