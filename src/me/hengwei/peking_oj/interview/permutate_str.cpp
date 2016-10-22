#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
void permutate_str(char* str, char* begin);
void iswap(char* src, char* dest);
int main() {
	char str[] = {"ABDCD"};
	char* begin = str;
	permutate_str(str, begin);
	return 0;
}

void permutate_str(char* str, char* begin) {
	char* pos;
	if(*begin == '\0') {
		printf("%s\n", str);
		return;
	}
	for(pos=begin; *pos != '\0'; pos++) {
		iswap(begin,pos);
		permutate_str(str, begin+1);
		iswap(begin,pos);
	}
}

void iswap(char* src, char* dest) {
	char temp = *src;
	*src = *dest;
	*dest = temp;
}

