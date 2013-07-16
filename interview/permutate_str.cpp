#include<iostream>
#include<cstdio>
using namespace std;
void permutate_str(char* str, char* begin);
int main() {
	char *str = "ABC";
	permutate_str(str, str);
	return 0;
}

void permutate_str(char* str, char* begin) {
	char* pos;
	if(*begin == '\0') {
		printf("%s\n", str);
		return;
	}
	for(pos=begin; *pos != '\0'; pos++) {
		swap(begin,pos);
		permutate_str(str, begin+1);
		swap(begin,pos);
	}
}

void swap(char* src, char* dest) {
	char temp = *src;
	*src = *dest;
	*dest = temp;
}

