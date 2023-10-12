/* Codeforces 1573A - Countdown
 * https://codeforces.com/problemset/problem/1573/A
 * rating: 800 | tags: greedy
 * source: accepted submission #129188966 (GNU C11) downloaded from Codeforces
 */

#include<stdio.h>
int main(){
	int a,ans,t,n;
	scanf("%d",&t);
	while(t--){
		ans=0;
		scanf("%d",&n);getchar();
		for(int i=1;i<n;i++){
			a=getchar()-'0';
			if(a!=0) ans+=a+1;
		}
		a=getchar()-'0';
		ans+=a;
		printf("%d\n",ans);
	}
}
