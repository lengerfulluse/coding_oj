#include<iostream>
#include<cstring>
using namespace std;
typedef struct node {
    int ele;
    node* left;
    node* right;
}node, *pnode;

int main() {
    int graph[10][10];
    /* the common operation for memset is to initialize 
     * or reset a series of memory chunk
     */
    memset(graph, 0, sizeof(graph));
    for(int i=0; i<10; i++) {
        for(int j=0; j<10; j++) {
            cout<<graph[i][j]<<"\t";
        }
        cout<<endl;
     }

     pnode n1 = new node();
     n1->ele = 4;
     n1->left = NULL;
     n1->right = NULL;
     pnode n2 = new node();
     n2->ele = 5;
     n2->left = NULL;
     n2->right = NULL;

     cout<<"before memcopy: "<<n1<<":"<<n1->ele<<"\t"<<n2<<":"<<n2->ele<<endl;
     pnode temp = new node();
     memcpy(temp, n1, sizeof(node));
     memcpy(n1, n2, sizeof(node));
     memcpy(n2, temp, sizeof(node));
     delete temp;
     cout<<"after memcopy: "<<n1<<":"<<n1->ele<<"\t"<<n2<<":"<<n2->ele<<endl;

     return 0;
}
