#include<stdio.h>
int joseph(int k);
static int j[14];

int main() {
    int k;
    scanf("%d", &k);
    while(k) {
        if(!j[k]) {
            j[k] = joseph(k); 
        }
        printf("%d\n", j[k]);
        scanf("%d", &k);
    }
    return 0;
}

int joseph(int k) {
    int size=2*k, len;    /* origin circle length */
    int m = k-1, j, pre, cur; 
    while(1) {
        m++;
        /* remove the impossible m */
        if(!((m+1)%(k+1) == 0 || m%(k+1) == 0))
            continue;
        len = size;
        if((pre = m%len) < k)
            continue;
        for(j=1; j < k; j++) {
            cur = (pre + m) % --len;  /* pos update per loop */
            if(cur < k) {
                break;
            }
            pre = cur;
         }
         if (j == k) {
            /* all bad guys are killed, got it */
            break;
         }
    }
    return m+1;
}
