/* Codeforces 1619A - Square String?
 * https://codeforces.com/problemset/problem/1619/A
 * rating: 800 | tags: implementation, strings
 * source: accepted submission #140031171 (GNU C11) downloaded from Codeforces
 */

#include<stdio.h>
#include<string.h>
int main ()
{
	int t;
	char s[210]; 
	scanf("%d\n",&t);
	while (t--)
	{
		gets(s);
		int x=strlen(s);
		if (x% 2 == 1) 
		{
			printf("NO\n");
			continue;
		}
		int flag = 0;
		int i;
		for (i=0;i<=x/2-1;i++)
		{
			if (s[i] == s[(x+1)/2+i]) continue;
			flag = 1;
		}
		if (flag) printf("NO\n");
		else printf("YES\n");
	}
}
