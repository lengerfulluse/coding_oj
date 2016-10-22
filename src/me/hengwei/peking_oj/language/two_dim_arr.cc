#include<iostream>
#include<vector>
using namespace std;

int main() {
    /* definition two dimension matrix */
    vector<vector<int> > two_dim(4, vector<int>(3,1));
    for(int row=0; row<4; row++) {
        for(int col=0; col<3; col++) {
            cout<<two_dim[row][col]<<"\t";
         }
         cout<<endl;
    }
    /* reverse matrix with iterator */
    vector< vector<int> >::iterator row_iter = two_dim.begin();
    while(row_iter != two_dim.end()) {
       vector<int>::iterator col_iter = (*row_iter).begin();
       while(col_iter != (*row_iter).end()) {
            cout<<*col_iter++<<"\t";
       }
       row_iter++;
       cout<<endl;
    }

    return 0;
}
