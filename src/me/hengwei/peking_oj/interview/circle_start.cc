#include<iostream>
using namespace std;

typedef struct Node {
    int ele;
    Node* next;
}Node, *pNode;

pNode find_circle_start(pNode root);
pNode create_circle_link();
void print_link(pNode root);

int main() {
    pNode root = create_circle_link();
    print_link(root);
    find_circle_start(root);
    return 0;
}
pNode find_circle_start(pNode root) {
    pNode fast, slow;
    if(!root || !root->next) {
        return NULL;
    }
    slow = root->next;
    fast = root->next->next;
    while(fast != slow && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
/*    cout<<"fast: "<<fast->ele<<"\tslow: "<<slow->ele<<endl;*/
    if(fast == slow) {
        cout<<"There exists a circle, there first meet at "<<fast->ele<<endl;
        /* now reset the slow pointer to the root and the fast pointer to the current, but change it to the slow pointer */
        slow = root->next;
        fast = fast->next;
        while(slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }
        cout<<"find start pointer:"<<slow->ele<<endl;
        return fast;
    }
    return NULL;
}

/* construct a link: 0->1->2->3->4->5->6->3 manually */
pNode create_circle_link() {
    pNode root = new Node();
    root->ele = 0;
    pNode first = new Node();
    first->ele = 1;
    root->next = first;
    pNode second = new Node();
    second->ele = 2;
    first->next = second;
    pNode third = new Node();
    third->ele = 3;
    second->next = third;
    pNode fourth = new Node();
    fourth->ele = 4;
    third->next = fourth;
    pNode fifth = new Node();
    fifth->ele = 5;
    fourth->next = fifth;
    pNode sixth = new Node();
    sixth->ele = 6;
    fifth->next = sixth;
    sixth->next = fourth;
    return root;
}

void print_link(pNode root) {
    int count = 0;
    pNode cur = root;
    while(cur && count<=7) {
        cout<<cur->ele<<'\t';
        cur = cur->next;
        count++;
    }
    cout<<endl;
}
