/* Codeforces 1466C - Canine poetry
 * https://codeforces.com/problemset/problem/1466/C
 * rating: 1300 | tags: dp, greedy, strings
 * source: accepted submission #102819215 (GNU C11) downloaded from Codeforces
 */

#include<stdio.h>
#include<string.h>
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n,sum,i;
		char s[100010];
		scanf("%s",s);
		n=strlen(s);
		for(sum=i=0;i<n-1;i++)
		{
			if(s[i]==s[i+1]&&s[i]!='1')
			{
				s[i+1]='1';
				sum++;
			}
			if(s[i]==s[i+2]&&s[i]!='1'){
				s[i+2]='1';
				sum++;
			}
		}
		printf("%d\n",sum);
	}
	return 0;
}
