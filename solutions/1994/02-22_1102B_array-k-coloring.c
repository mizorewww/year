/* Codeforces 1102B - Array K-Coloring
 * https://codeforces.com/problemset/problem/1102/B
 * rating: 1400 | tags: greedy, sortings
 * source: accepted submission #48130403 (GNU C11) downloaded from Codeforces
 */

#include<stdio.h>
int main(){
	int n,k,i,j,color=0;
	int a[5000];
	int c[5000]={0};
	int num[5000]={0};
	scanf("%d %d",&n,&k);
	for(i=0;i<n;i++)scanf("%d",&a[i]);
	for(i=0;i<n;i++){
		num[a[i]-1]++;
		if(num[a[i]-1]>k){
			printf("NO");
			return 0;
		}
	}
	for(i=0;i<5000;i++){
		if(num[i]){
			for(j=0;j<n;j++){
				if(a[j]==i+1){
					c[j]=color%k+1;
					color++;
				}
			}
		}
	}
	printf("YES\n");
	for(i=0;i<n;i++)printf("%d ",c[i]);
	return 0;
}
