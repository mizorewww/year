/* Codeforces 725C - Hidden Word
 * https://codeforces.com/problemset/problem/725/C
 * rating: 1600 | tags: brute force, constructive algorithms, implementation, strings
 * source: accepted submission #21687679 (GNU C) downloaded from Codeforces
 */

#include<stdio.h>
int main() 
{
	char s[28];
	char map[3][14];
	int i,j,l,r,mid,n;
	scanf("%s",s+1);
	for(i=1;i<=26;i++) 
		for(j=i+1;j<=27;j++)
			if(s[i]==s[j])
			{
				l=i;
				r=j;
			}
	if(r-l==1)
		printf("Impossible");
	else
	{
		mid=(r-1-l)/2;
		n=r-mid;
		for(i=1;i<=13;)
		{
			if(n!=l)
			{
				map[1][i]=s[n];
				i++;
			}
			n++;
			if(n==28)
				n=1;
		}
		for(i=13;i>0;)
		{
			if(n!=l)
			{
				map[2][i]=s[n];
				i--;
			}
			n++;
			if(n==28)
				n=1;

		}
		for(i=1;i<=2;i++)
		{
			for(j=1;j<=13;j++)
				printf("%c",map[i][j]);
			printf("\n");
		}
	}
	return 0;
}
