#include<iostream>
#include<cstdlib>
#include<cassert>
#include<limits>
using namespace std;
int my_atoi(char* str);
int main()
{
    char* str = "+23563";
    char* str1 = "-2345";
    char* str2 = "2332433957935723953723957295";
    cout<<str<<" Become:  "<<my_atoi(str)<<endl;
    cout<<str1<<" Become:  "<<my_atoi(str1)<<endl;
    cout<<str2<<" Become:  "<<my_atoi(str2)<<endl;
    return 0;
}

/* the most trap doesn't lie in the conversion method
 * but the critical condition, mainly divide into four aspects:
 * 1. string is empty or pointer is NULL.
 * 2. Prefix characters, such as blank, space.
 * 3. plus or minus characters.
 * 4. number overflow. you should give a long long int type, and 
 *    compare to the numeric::limits<int>max() every time.
 */
int my_atoi(char* str) {
    assert(str != NULL);
    bool flag= true;
    long long num = 0;
    char* pos = str;
    if(*pos == '-') {
        flag = false;
        pos++;
    } else if(*pos == '+') {
        flag = true;
        pos++;
    }
    while(*pos != '\0') {
        if(*pos > '9' || *pos < '0') {
            cout<<"Invalidate string"<<endl;
            exit(1);
        }
        num = num * 10 + (*pos - '0');
        /* conversion overflow judge */ 
        if(num > numeric_limits<int>::max()) {
            num = 0;
            cout<<"string conversion overflow!"<<endl;
            exit(1);
        }
        pos++;
   }
   if(flag == false) {
       num = -1*num; 
   }
   return num;
}
