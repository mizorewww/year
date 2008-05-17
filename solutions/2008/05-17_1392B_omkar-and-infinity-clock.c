/* Codeforces 1392B - Omkar and Infinity Clock
 * https://codeforces.com/problemset/problem/1392/B
 * rating: 800 | tags: implementation, math
 * source: accepted submission #90131110 (GNU C11) downloaded from Codeforces
 */

#include<stdio.h>
#include<math.h>
int main(){
	int t;
	scanf("%d",&t);
	while(t){
		int n;
		unsigned long k;
		scanf("%d%lu",&n,&k);
		long int arr[n],i;
		long int high=-1000000000,low=1000000000;
		for(i=0;i<n;i++){
			scanf("%ld",&arr[i]);
			if(arr[i]<low){
				low=arr[i];
			}
			if(arr[i]>high){
				high=arr[i];
			}
		}
		if(k%2==0){
			for(i=0;i<n;i++){
				printf("%ld ",arr[i]-low);
			}
		}
		else{
			for(i=0;i<n;i++){
				printf("%ld ",high-arr[i]);
			}
		}
		printf("\n");
		t--;
	} 
	return 0;	
}
