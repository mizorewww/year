/* Codeforces 1405B - Array Cancellation
 * https://codeforces.com/problemset/problem/1405/B
 * rating: 1000 | tags: constructive algorithms, implementation
 * source: accepted submission #92053657 (GNU C11) downloaded from Codeforces
 */

#include<stdio.h>

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		long long int a[100001];
		long long int sum=0,sum_=0;
		int j=0;
		for(int i=0;i<n;i++){
			scanf("%lld",&a[i]);
			sum+=a[i];
			if(sum>=0){
				continue;
			}
			if(sum<0){
				sum_+=-sum;
				sum=0;
			}
		}
		printf("%lld\n",sum_);
	}
}
