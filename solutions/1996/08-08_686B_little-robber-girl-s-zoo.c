/* Codeforces 686B - Little Robber Girl's Zoo
 * https://codeforces.com/problemset/problem/686/B
 * rating: 1100 | tags: constructive algorithms, implementation, sortings
 * source: accepted submission #18676677 (GNU C) downloaded from Codeforces
 */

#include <stdio.h>

int main(){
	int i,j,n,a[105];
	scanf("%d",&n);
	for(i=0;i<n;i++)scanf("%d",&a[i]);
	for(i=n-1;i>=0;i--){
		for(j=0;j<i;j++){
			if(a[j]>a[j+1]){
				int temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
				printf("%d %d\n",j+1,j+2);
			}
		}
	}
	return 0;
}
