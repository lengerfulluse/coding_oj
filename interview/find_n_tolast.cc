#include<iostream>
using namespace std;
typedef struct node {
	int ele;
	node *next;
}Node, *pNode;

pNode init_list();
void print_list(pNode root);
int find_n_tolast(pNode root, int n);
int main() {
	pNode root = init_list();
	print_list(root);
	cout<<find_n_tolast(root, 1)<<endl;
}

/* the key point lies in the boundary condition judgement.
 * often the most common method to do is to constuct two points
 * then move iterately.
 */

int find_n_tolast(pNode root, int n) {
	if(!root || n<1) {
		return NULL;
	}
	pNode pre, cur;
	pre = cur = root;
	/* when n = 1, the cur pointer is the position start */
	while(cur && n>1) {
		n--;
		cur = cur->next;
	}
	/* terminal by the current empty. */
	if(n > 1) {
		return NULL;
	}
	while(cur->next) {
		pre = pre->next;
		cur = cur->next;
	}
	return pre->ele;
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


/* what need to be concerned:
 * 1. boundary n >= 1 and root is not empty.
 * 2. move boundary condition limited. we stop move on n = 1 or forward point is empty.
 */