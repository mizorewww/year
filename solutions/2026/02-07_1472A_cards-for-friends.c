/* Codeforces 1472A - Cards for Friends
 * https://codeforces.com/problemset/problem/1472/A
 * rating: 800 | tags: greedy, math
 * source: accepted submission #103193065 (GNU C11) downloaded from Codeforces
 */

#include<stdio.h>
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int w,h,n,m=1;
		scanf("%d %d %d",&w,&h,&n);
		while(w%2==0){
			w=w/2;
			m=m*2;
		}
		while(h%2==0){
			h=h/2;
			m=m*2;
		}
		if(m>=n){
			printf("YES\n");
		}
		else{
			printf("NO\n");
		}
	}
}
