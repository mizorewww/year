/* Codeforces 1132B - Discounts
 * https://codeforces.com/problemset/problem/1132/B
 * rating: 900 | tags: greedy, sortings
 * source: accepted submission #50837565 (GNU C11) downloaded from Codeforces
 */

#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>

int cmp(const void *a,const void *b){
	return *(int *)b-*(int *)a;
}

long long a[300000];

int main(){
	int n;
	int m,q;
	long long res=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%I64d",&a[i]);
		res+=a[i];
	}
	scanf("%d",&m);
	qsort(a,n,sizeof(a[0]),cmp);
	for(int i=0;i<m;i++){
		scanf("%d",&q);
		long long daan=res;
		daan-=a[q-1];
		printf("%I64d\n",daan);
	}
}
