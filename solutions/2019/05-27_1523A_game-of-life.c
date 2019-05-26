/* Codeforces 1523A - Game of Life
 * https://codeforces.com/problemset/problem/1523/A
 * rating: 800 | tags: implementation
 * source: accepted submission #117884735 (GNU C11) downloaded from Codeforces
 */

#include<stdio.h>
#include<string.h>
char s1[1100],s2[1100];

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n,m;
		scanf("%d%d",&n,&m);
		scanf("%s",s1);
		while(m--)
		{
			int flag=0;
			memcpy(s2,s1,sizeof(s1));
			for(int i=0;i<n;i++)
			{
				if(i==0 && s1[i]=='0' && s1[i+1]=='1')
				{
					s2[i]='1';
					flag=1;
				 } 
				if(i==n-1 && s1[i]=='0' && s1[i-1]=='1')
				{
					s2[i]='1';
					flag=1;
				 } 
				if(i!=0 && i!=n-1 && s1[i]=='0')
				{
					int count=0;
					if(s1[i-1]=='1') count++;
					if(s1[i+1]=='1') count++;
					if(count==1)
					{
						s2[i]='1';
						flag=1;
					 } 
				}
			}
			memcpy(s1,s2,sizeof(s2));
			if(!flag) break;
		}
		printf("%s\n",s1);
	}
 }
