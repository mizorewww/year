/* Codeforces 840A - Leha and Function
 * https://codeforces.com/problemset/problem/840/A
 * rating: 1300 | tags: combinatorics, greedy, math, number theory, sortings
 * source: accepted submission #29572556 (GNU C) downloaded from Codeforces
 */

#include <stdio.h>

typedef struct nodes{
    int i,j;
}node;


int cmp(const void * c,const void *d){
    return *(int *)d-*(int *)c;
}

int cmp2(const void * c,const void *d){
    return ((node *)c)->i-((node *)d)->i;
}

int a[200010],ans[200010],n,k,x;
node b[200010];

int main(void) {
	scanf("%d",&n);
	for(x=0;x<n;x++){
	    scanf("%d",&a[x]);
	}
	for(x=0;x<n;x++){
	    scanf("%d",&(b[x].i));
	    b[x].j=x;
	}
	qsort(a,n,sizeof(int),cmp);
	qsort(b,n,sizeof(node),cmp2);
	for(x=0;x<n;x++){
	    ans[b[x].j]=a[x];
	}
	for(x=0;x<n;x++){
	    printf("%d ",ans[x]);
	}
	return 0;
}
