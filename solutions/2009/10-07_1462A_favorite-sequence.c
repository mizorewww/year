/* Codeforces 1462A - Favorite Sequence
 * https://codeforces.com/problemset/problem/1462/A
 * rating: 800 | tags: implementation, two pointers
 * source: accepted submission #101270670 (GNU C11) downloaded from Codeforces
 */

#include<stdio.h>
int main(){
	int t,n;
	int p[305];
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=0; i<n; i++)
			scanf("%d",&p[i]);
		int left = 0,right = n-1;
		while(left <= right){
			printf("%d ",p[left++]);
			if(left > right) break;
			printf("%d ",p[right--]);
		}
		printf("\n");
	}
	return 0;
}
