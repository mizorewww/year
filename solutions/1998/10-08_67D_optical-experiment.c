/* Codeforces 67D - Optical Experiment
 * https://codeforces.com/problemset/problem/67/D
 * rating: 1900 | tags: binary search, data structures, dp
 * source: accepted submission #334422 (GNU C) downloaded from Codeforces
 */

#include <stdio.h>
#define N 1000001

int a[N],n,b[N],c[N],d[N],t[N]={0},i,j,r,rm=0;

int main() {
    scanf("%d",&n);
    for (i=0;i<n;i++) scanf("%d",&a[i]);
    for (i=0;i<n;i++) c[a[i]]=i;    
    for (i=0;i<n;i++) scanf("%d",&b[i]);
    for (i=0;i<n;i++) d[c[b[i]]]=i;
    for (i=0;i<n;i++) {
	    for (j=n-d[i]-1,r=0; j>=0; j=(j&(j+1))-1) if (t[j]>r) r=t[j];
	    r+=1;
        for (j=n-d[i]-1; j<n; j=(j|(j+1))) if(t[j]<r) t[j]=r;
        if (r>rm) rm=r;
    }
    printf("%d",rm);
    
    return 0;
}
