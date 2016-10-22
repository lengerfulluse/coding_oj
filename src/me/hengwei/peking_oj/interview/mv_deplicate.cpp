#include<iostream>
using namespace std;
typedef struct node {
	int ele;
	node *next;
}Node, *pNode;

pNode init_list();
void print_list(pNode root);
void mv_duplicate(pNode root);
bool is_exists(pNode root, pNode cur);

int main() {
	pNode root = init_list();
	print_list(root);
	mv_duplicate(root);
	print_list(root);
	return 0; 
}

pNode init_list() {
	int loop=1;
	pNode root, pre, cur;
	root = new Node();
	root->ele = 0;
	root->next = NULL;
	pre = root;
	for(; loop<10; ++loop) {
		cur = new Node();
		cur->ele = loop;
		cur->next = NULL;
		pre->next = cur;
		pre = cur;
	}
	/* add extra duplication element 3 for test. */
	cur = new Node();
	cur->ele = 3;
	cur->next = NULL;
	pre->next = cur;
	return root;
}

void print_list(pNode root) {
	pNode loop = root;
	while(loop) {
		cout<<loop->ele<<"\t";
		loop = loop->next;
	}
	cout<<endl;
}

/* main two time complexity algorithms.
 * O(n^2)
 * O(n)
 */
void mv_duplicate(pNode root) {
	if(!root) {
		return;
	}
	pNode cur = root, pre = NULL;
	while(cur) {
		if(is_exists(root, cur)) {
			pre->next = cur->next;
			delete cur;
			cur = pre->next;
		} else{
			pre = cur;
			cur = cur->next;
		}
	}
}

bool is_exists(pNode root, pNode cur) {
	if(!root || !cur) {
		return false;
	}
	/* if two points are equal, then its addressed equal.
	 * not their address.
	 */
	while(root != cur) {
		if (root->ele == cur->ele) {
			return true;
		}
		root = root->next;
	}
	return false;
}