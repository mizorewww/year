/* Codeforces 1209A - Paint the Numbers
 * https://codeforces.com/problemset/problem/1209/A
 * rating: 800 | tags: greedy, implementation, math
 * source: accepted submission #60548229 (GNU C11) downloaded from Codeforces
 */

#include<stdio.h>

int cf(const void *a,const void *b){
	return (*(int*)a-*(int*)b);
}

int main(){
	int n;
	scanf("%d",&n);
	int num[n];
	int i,j,k=0;
	for(i=0;i<n;i++)scanf("%d",&num[i]);
	qsort(num,n,sizeof(int),cf);
	for(i=0;i<n;i++){
		if(num[i]==-1)continue;
		for(j=i+1;j<n;j++){
			if(num[j]%num[i]==0)num[j]=-1;
		}
		num[i]=-1;
		k++;
	}
	printf("%d",k);
}
