/* Codeforces 975C - Valhalla Siege
 * https://codeforces.com/problemset/problem/975/C
 * rating: 1400 | tags: binary search
 * source: accepted submission #37810557 (GNU C) downloaded from Codeforces
 */

#include <stdio.h>

int wa[200000];
long long sum[200000];
int main(){
	
	int n,q,i,l1,l2,m;
	long long arr,k,res;
	scanf("%d %d",&n,&q);
	scanf("%d",&wa[0]);
	sum[0]=wa[0];
	for(i=1;i<n;i++){
		scanf("%d",&wa[i]);
		sum[i]=sum[i-1]+wa[i];
	}
	arr=0;
	while(q--){
		scanf("%lld",&k);
		arr+=k;
		if(arr>=sum[n-1])arr=0;
			l1=0;
			l2=n-1;
			while(l2>l1){
				m=(l2+l1)/2;
				if(sum[m]>arr){
					l2=m;
				}
				else{
					l1=m+1;
				}
			}
		printf("%d\n",n-l1);
	}
	
	return 0;
}
