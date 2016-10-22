#include<iostream>
#include<cstdlib>
#include<stack>
#include<cassert>
using namespace std;
#define INFINITE 0.000001
int infix_cal(char* str);
void calculate(stack<int> &num, char ope);
int main() {
    char str[] = "3+4*8/2";
    cout<<"calculate: "<<str<<endl;
    cout<<"result: "<<infix_cal(str)<<endl;
    return 0;
}
/* for the stack, the reference parameter pass is very important */
void calculate(stack<int> &num, char ope) {
    assert(num.size() >= 2);
    int right = num.top();
    num.pop();
    int left = num.top();
    num.pop();
    switch(ope) {
        case '+':
            num.push(left+right);
            break;
        case '-':
            num.push(left-right);
            break;
        case '*':
            num.push(left*right);
            break;
        case '/':
            /* assume that the denominator is not equal zero */
            assert(abs(right) > INFINITE);
            num.push(left/right);
            break;
        default:
            cout<<"Error Operator: "<<ope<<endl;
    }
}

int infix_cal(char* str) {
    assert(str != NULL);
    char* begin = str;
    stack<int> num;
    stack<char> ope;
    while(*begin != '\0') {
        cout<<*begin<<"\t";
        if(*begin == ' ' || *begin == '\t') {
            begin++;
            continue;
        }
        /* assume here that the input number are all single digit */
        if(*begin > '0' && *begin < '9') {
            num.push(atoi(begin));

        } else {
            switch(*begin) {
                case '+':
                    while(!ope.empty()) {
                        char cur = ope.top();
                        ope.pop();
                        calculate(num, cur);
                    }
                    ope.push('+');
                    break;
                case '-':
                    while(!ope.empty()) {
                        char cur = ope.top();
                        ope.pop();
                        calculate(num, cur);
                    }
                    ope.push('-');
                    break;
                case '*':
                    while(!ope.empty() && ope.top() != '-' && ope.top() != '+') {
                        char cur = ope.top();
                        ope.pop();
                        calculate(num, cur);
                    }
                    ope.push('*');
                    break;
                case '/':
                    while(!ope.empty() && ope.top() != '-' && ope.top() != '+') {
                        char cur = ope.top();
                        ope.pop();
                        calculate(num, cur);
                    }
                    ope.push('/');
                    break;
                default:
                    cout<<"Error: Illegal operator "<<*begin<<endl;
           }
       }
       begin++;
    }
    cout<<endl;
    while(!num.empty() && !ope.empty()) {
        char cur = ope.top();
        calculate(num, cur);
        ope.pop();
    }
    assert(num.size() == 1 && ope.size() == 0);
    return num.top();
}
