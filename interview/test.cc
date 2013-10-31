#include<stdio.h>
enum {A, B, C=50, D=B+1, E};
int main() {
    printf("%d, %d, %d, %d, %d", A, B, C, D, E);
}
