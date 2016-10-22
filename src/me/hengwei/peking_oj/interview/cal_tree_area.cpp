#include<iostream>
#include<queue>
#include<cstdlib>
using namespace std;
typedef struct Node {
    int ele;
    Node* left;
    Node* right;
}Node, *pNode;
int max_width = 0;

pNode init_tree();
void BFS(pNode root);
void DFS(pNode root);
int cal_tree_depth(pNode root);
void cal_tree_width(pNode root);
void cal_tree_level_width(queue<pNode> par_level);

int main() {
    pNode root = init_tree();
    cout<<"depth of tree: "<<cal_tree_depth(root)<<endl;
    cal_tree_width(root);
    cout<<"width of tree: "<<max_width<<endl;
    return 0;
}

int cal_tree_depth(pNode root) {
    if(root == NULL) {
        return 0;
    }
    return 1+max(cal_tree_depth(root->left), cal_tree_depth(root->right));
}

void cal_tree_width(pNode root) {
    if(root == NULL) {
        return;
    }
    queue<pNode> level_que;
    level_que.push(root);
    cal_tree_level_width(level_que);
}

void cal_tree_level_width(queue<pNode> par_level) {
    if(par_level.empty()) {
        return;
    }
    max_width = max(int(par_level.size()), max_width);
    queue<pNode> level;
    while(!par_level.empty()) {
        pNode node = par_level.front();
        par_level.pop();
        if(node->left) {
            level.push(node->left);
        }
        if(node->right) {
            level.push(node->right);
        }
    }
    cal_tree_level_width(level);
}
        

int max(int a, int b) {
    return a>b ? a : b;
}

void DFS(pNode root) {
    /* three kind of DFS is pre-order,
     * in-order, post-order
     */
    
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
