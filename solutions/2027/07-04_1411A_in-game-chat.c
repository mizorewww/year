/* Codeforces 1411A - In-game Chat
 * https://codeforces.com/problemset/problem/1411/A
 * rating: 800 | tags: implementation
 * source: accepted submission #101882302 (GNU C11) downloaded from Codeforces
 */

#include<stdio.h>
int main ()
{
	int i,t,n,index;
	char s[100];
	scanf("%d",&t);
	while(t--){
		scanf("%d\n",&n);
		gets(s);
		for(i=n-1;i>=0;i--){
			if(s[i]!=')')break;
		}
		if(i==-1)printf("Yes\n");
		else if(i+1<n-i-1)printf("Yes\n");
		else printf("No\n");
}
	return 0;
 }
