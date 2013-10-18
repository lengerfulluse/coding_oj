#include<iostream>
#include<vector>
#include<cassert>
using namespace std;
void dynamic_programming(vector<int> a);
int main() {
    vector<int> a;
    a.push_back(1);
    a.push_back(5);
    a.push_back(8);
    a.push_back(2);
    a.push_back(3);
    a.push_back(4);
    dynamic_programming(a);
    return 0;
}

/* the space complexity is O(n^2)
 * the time complexity is also O(n^2)
 */
void dynamic_programming(vector<int> a) {
    assert(a.size() > 0);
    vector< vector<int> > max_seq;
    /* initialize the first max_seq */
    vector<int> temp(1,a[0]);
    max_seq.push_back(temp);

    for(int i=1; i<a.size(); i++) {
        int max_index= -1;
        int max_size = 0;
        for(int j=0; j<i; j++) {
            if(a[j] <= a[i]) {
                int cur_size = max_seq[j].size(); 
                if(max_size < cur_size) {
                    max_size = cur_size;
                    max_index = j;
                }
            }
         }
         vector<int> temp(max_seq[max_index]);
         temp.push_back(a[i]);
         max_seq.push_back(temp);
    }
    int max = -1; 
    /* temp variable copy */
    for(int i=0; i<max_seq.size(); i++) {
        if(max < int(max_seq[i].size())) {
            max = int(max_seq[i].size());
        }
    }

    for(int i=0; i<max_seq.size(); i++) {
        if(max == max_seq[i].size()) {
            vector<int> temp = max_seq[i];
            for(int j=0; j<temp.size(); j++) {
                cout<<temp[j]<<"\t";
            }
            cout<<endl;
        }
    }
}


/* note for this longest increase sub_sequence string 
 * 1. Construct the 2-dimension array, we could use a temporary variable
 *    to store the middle-value, and add it to the final vector array.
 * 2. Especially for the c/c++, size_t is unsigned integer value, it 
 *    must be converted to int. Otherwise it will get wrong result.
 */
