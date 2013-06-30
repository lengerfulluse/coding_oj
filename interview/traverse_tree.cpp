#include<iostream>
#include<queue>
using namespace std;
typedef struct Node {
    int ele;
    Node* left;
    Node* right;
}Node, *pNode;

pNode init_tree();
void BFS(pNode root);
void DFS(pNode root);

int main() {
    pNode root = init_tree();
    BFS(root);
    return 0;
}

void BFS (pNode root) {
    if(!root)
        return;
    queue<pNode> que;
    que.push(root);
    while(!que.empty()) {
        pNode p = que.front();
        que.pop();
        cout<<p->ele<<endl;
        if(p->left) {
            que.push(p->left);
        }
        if(p->right) {
            que.push(p->right);
        }
    }
}
    
pNode init_tree() {
    pNode root = new Node();
    pNode left, right;
    root->ele = 1;
    root->left = new Node();
    root->left->ele = 2;
    left = root->left;
    root->right = new Node();
    root->right->ele = 3;
    right = root->right;
    left->left = new Node();
    left->left->ele = 4;
    left->left->left = NULL;
    left->left->right = NULL;

    left->right = new Node();
    left->right->ele = 5;
    left->right->left = NULL;
    left->right->right = NULL;

    right->left = new Node();
    right->left->ele = 6;
    right->left->left = NULL;
    right->left->right = NULL;
    right->right = new Node();
    right->right->ele = 7;
    right->right->left = NULL;
    right->right->right = NULL;

    return root;
}
