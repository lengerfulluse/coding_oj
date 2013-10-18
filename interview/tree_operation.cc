#include<iostream>
#include<queue>
#include<stack>
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
void pre_order(pNode root);
void pre_order_iter(pNode root);
void in_order(pNode root);
void in_order_iter(pNode root);
void post_order(pNode root);

int main() {
    pNode root = init_tree();
    pre_order(root);
    cout<<endl;
    pre_order_iter(root);
    cout<<endl;
    in_order(root);
    cout<<endl;
    in_order_iter(root);
    cout<<endl;
    post_order(root);
    cout<<endl;
    return 0;
}

void pre_order(pNode root) {
    if(root == NULL) {
        return;
    }
    cout<<root->ele<<"\t";
    pre_order(root->left);
    pre_order(root->right);
}
/* preorder simple put the right into stack first,
 * and then put the left
 */
void pre_order_iter(pNode root) {
    if(root == NULL) {
        return;
    }
    stack<pNode> nodes;
    nodes.push(root);
    while(!nodes.empty()) {
        pNode node = nodes.top();
        nodes.pop();
        cout<<node->ele<<"\t";
        if(node->right != NULL) {
            nodes.push(node->right);
        }
        if(node->left != NULL) {
            nodes.push(node->left);
        }
    }
}

void in_order(pNode root) {
    if(root == NULL) {
        return;
    }
    in_order(root->left);
    cout<<root->ele<<"\t";
    in_order(root->right);
}

/* if the left node is not empty, just continue the while
 * loop, otherwise we should pop the top element, and assign
 * the right child to the current node. Which just resolve the 
 * pop stack when right children is NULL in a clever way.
 */
void in_order_iter(pNode root) {
    stack<pNode> nodes;
    while(!nodes.empty() || root) {
        if(root) {
            nodes.push(root);
            root = root->left;
        }
        if(!root) {
            root = nodes.top();
            cout<<root->ele<<"\t";
            nodes.pop();
            root = root->right;
        }
    }
    cout<<endl;
}

void post_order(pNode root) {
    if(root == NULL) {
        return;
    }
    post_order(root->left);
    post_order(root->right);
    cout<<root->ele<<"\t";
}

void post_order_iter(pNode root) {
    
int max(int a, int b) {
    return a>b ? a : b;
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
