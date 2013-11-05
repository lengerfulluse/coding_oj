#include<iostream>
#include<cassert>
using namespace std;
typedef struct trienode {
    int word;
    int prefix;
    trienode* ref[26];
}trienode;

void initialize(trienode* node);
void add_word(trienode* node, char* word);
int count_word(trienode* node, char* word);
int count_prefix(trienode* node, char* word);

int main() {
    trienode* root = new trienode();
    initialize(root);
    add_word(root, "abcd");
    add_word(root, "abce");
    cout<<"abc->"<<count_prefix(root, "abc")<<endl;
    return 0;
}
void initialize(trienode* node) {
    assert(node != NULL);
    node->word = 0;
    node->prefix = 0;
    for(int i=0; i<26; i++) {
        node->ref[i] = NULL;
    }
}

void add_word(trienode* node, char* word) {
    if(*word == '\0') {
        node->word += 1;
    } else {
        node->prefix += 1;
        int ref_index = *word - 'a';
        if(node->ref[ref_index] == NULL) {
            node->ref[ref_index] = new trienode();
            initialize(node->ref[ref_index]);
        }
        word++;
        add_word(node->ref[ref_index], word);
    }
}

int count_word(trienode* node, char* word) {
    assert(node != NULL);
    if(*word == '\0') {
        return node->word;
    } else {
        int ref_index = *word - 'a';
        if(node->ref[ref_index] == NULL) {
            return 0;
        } else {
            word++;
            count_word(node->ref[ref_index], word);
        }
    }
}

int count_prefix(trienode* node, char* word) {
    assert(node != NULL);
    if(*word == '\0') {
        return node->prefix;
    } else {
        int ref_index = *word - 'a';
        if(node->ref[ref_index] == NULL) {
            return 0;
        } else {
            word++;
            count_prefix(node->ref[ref_index], word);
        }
    }
}
