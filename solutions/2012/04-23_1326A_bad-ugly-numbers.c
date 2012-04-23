/* Codeforces 1326A - Bad Ugly Numbers
 * https://codeforces.com/problemset/problem/1326/A
 * rating: 1000 | tags: constructive algorithms, number theory
 * source: accepted submission #73688980 (GNU C11) downloaded from Codeforces
 */

#include<stdio.h>
int main(){
	int t,n,a[100001],i;
	scanf("%d",&t);
	while(t--){
		i=0;
		scanf("%d",&n);
		if(n==1) printf("-1\n");
		else{
			printf("2");
			while(--n) 
			printf("3");
			printf("\n");
		} 
	}
}
