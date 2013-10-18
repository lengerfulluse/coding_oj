#include<iostream>
#include<vector>

using namespace std;
int main() {
    vector<int> a(5);
    int b = -1;
    int max  = b > a.size() ? b : a.size();
    cout<<"a.size(): " <<a.size()<<endl;
    cout<<"b: "<<b<<endl;
    cout<<"max: "<<max<<endl;
    return 0;
}
