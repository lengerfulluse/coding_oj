#include<iostream>
#include<cassert>
using namespace std;
typedef struct node {
    int ele;
    node* next;
}node;
/* declaration should be put after the node definition */
node* reverse_links(node* head);
void print_link(node* head);
int main() {
    /* initialize link */
    node* head = new node();
    head->ele = 1;
    node* pnext = new node();
    head->next = pnext;
    pnext->ele = 2;
    node* next_2 = new node();
    pnext->next = next_2;
    next_2->ele = 3;
    next_2->next= NULL;
    
    print_link(head);
    print_link(reverse_links(head));

    return 0;
}

node* reverse_links(node* head) {
    assert(head != NULL);
    node* pre = NULL;
    node* cur = head;
    while(cur->next) {
        node* next = cur->next;
        cur->next = pre;
        pre = cur;
        cur = next;
    }
    cur->next = pre;
    return cur;
}

void print_link(node* head) {
    node* p = head;
    while(p) {
        cout<<p->ele<<"\t";
        p = p->next;
    }
    cout<<endl;
}
