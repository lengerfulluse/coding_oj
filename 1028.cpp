#include<iostream>
#include<stack>
#include<string>
#include<vector>
#include<sstream>
using namespace std;

/* const for no change, and reference & for not copy */
vector<string> split(const string &s, char delim) {
    vector<string> elems;
    stringstream ss(s);
    string item;
    while(getline(ss, item, delim)) {
        elems.push_back(item);
    }
    return elems;
}

int main() {
    char input[80];
    vector<string> command;
    stack<string> forward;
    stack<string> back;
    string cur_url("http://www.acm.org/");
    while(cin.getline(input, 80)) {
        string str_input(input);
        command = split(str_input, ' ');    
        if(command[0] == "VISIT") {
            if(!cur_url.empty()) {
                back.push(cur_url);  
            }
            cur_url = command[1];
            /* reset the forward stack */
            forward = stack<string>();
            cout<<cur_url<<endl;
        } else if(command[0] == "BACK") {
            if(back.empty()) {
                cout<<"Ignored"<<endl;
                continue;
            }else if(!cur_url.empty()) {
                forward.push(cur_url);
                cur_url = back.top();
                back.pop();
            }
            cout<<cur_url<<endl;
        } else if(command[0] == "FORWARD") {
            if(forward.empty()) {
                cout<<"Ignored"<<endl;
                continue;
            } else if(!cur_url.empty()) {
                back.push(cur_url);
                cur_url = forward.top();
                forward.pop();
            }
            cout<<cur_url<<endl;
        } else if(command[0] == "QUIT") {
            break;
        }
    }
    return 0;
}
