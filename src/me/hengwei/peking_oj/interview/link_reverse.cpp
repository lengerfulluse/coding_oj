/* the key: add new point, but avoid the loop point, namely, delete used point */
#include<iostream>
using namespace std;

typedef struct Node {
    int ele;
    Node* next;
}Node, *pNode;

pNode reverse_link_recur(pNode root);
pNode reverse_link_iter(pNode root);
pNode init_link();
void print_link(pNode root);
int main() {
    pNode root = init_link();
    print_link(root);
    print_link(reverse_link_iter(root));
    return 0;
}

pNode reverse_link_recur(pNode root) {
    if(!root->next) {
        return root;
    }
    pNode result = reverse_link_recur(root->next);
    root->next->next = root;
    root->next = NULL;  //leave the forward link
    return result;
}

pNode reverse_link_iter(pNode root) {
    pNode result = NULL;
    pNode p = root, temp;
    if(!p)
        return p;
    pNode cur = p->next;
    p->next = NULL;
    while(cur) {
       temp = cur->next;
       cur->next = p;
       p = cur;
       cur = temp;
    }
    return p;
}

pNode init_link() {
    int i=1;
    pNode root = new Node();
    pNode pre;
    root->ele = 0;
    root->next = NULL;
    pre = root;
    while(i <= 6) {
        pNode node = new Node();
        node->ele = i;
        node->next = NULL;
        pre->next = node;
        pre = node;
        i++;
    }
    return root;
}

void print_link(pNode root) {
    pNode p = root;
    while(p) {
        cout<<p->ele<<"\t";
        p = p->next;
    }
    cout<<endl;
}
