/* Codeforces 1136B - Nastya Is Playing Computer Games
 * https://codeforces.com/problemset/problem/1136/B
 * rating: 1000 | tags: constructive algorithms, math
 * source: accepted submission #51180189 (GNU C11) downloaded from Codeforces
 */

#include<stdio.h>

int min(int a,int b) {
    if(a<b) return a;
    return b;
}

int main() {
    int n,k;
    scanf("%d%d",&n,&k);
    printf("%d\n",min(k-1,n-k)+3*n);
}
