#include<iostream>
#include<map>
using namespace std;


void initial(map<char, int> & char_to_num) {
    int num=1, loop=0, step=3;
    char c = 'A'; 
    while(c < 'Z') {
        if(c == 'Q') {
            c++;
            continue;
        }
        if(loop % step == 0)
            num++;
        pair<char, int> tmp(c, num);
        char_to_num.insert(tmp);
        loop++;
        c++;
    }
}

void convert_count(map<char, int> & char_to_num) {
    int total=0, loop=0, dup_flag=false;
    string dial_num;
    map<string, int> dial_count;
    cin>>total;
    while(loop++ < total) {
        cin>>dial_num; 
        string format;
        string::iterator iter = dial_num.begin();
        while(iter != dial_num.end()) {
            if(*iter == '-') {
                iter++;
                continue;
            }
            else if(char_to_num.count(*iter) != 0) {
                format.push_back('0'+char_to_num[*iter]);
            } else {
                format.push_back(*iter);
            }
            iter++;
        }
        format.insert(3,"-"); 
        dial_count[format]++;
//        map<string, int>::iterator find_iter = dial_count.find(format);
//        if(find_iter == dial_count.end())
//            dial_count.insert(map<string, int>::value_type(format,1));
//        else
//            dial_count[format]++;
    }
    map<string, int>::iterator iter = dial_count.begin();
    while(iter != dial_count.end()) {
        if(iter->second > 1) {
            cout << iter->first << " " << iter->second <<endl;
            dup_flag = true;
        }
        iter++;
    }
    if(!dup_flag)
        cout <<"No duplicates."<<endl;
}

int main() {
    map<char, int> char_to_num;
    initial(char_to_num);
    convert_count(char_to_num);    
    return 0;
}
