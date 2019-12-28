/* Codeforces 746D - Green and Black Tea
 * https://codeforces.com/problemset/problem/746/D
 * rating: 1500 | tags: constructive algorithms, greedy, math
 * source: accepted submission #23093707 (GNU C) downloaded from Codeforces
 */

#include<stdio.h>
typedef unsigned u;
char A[111111];
int main()
{
	u n,k,a,b,i=0,l=0;char p='?';
	scanf("%u%u%u%u",&n,&k,&a,&b);
	while(a||b)
	{
		if(a>b)
		{
			if(p=='G'&&l==k)
			{A[i]='B';--b;}
			else
			{A[i]='G';--a;}
		}
		else
		{
			if(p=='B'&&l==k)
			{A[i]='G';--a;}
			else
			{A[i]='B';--b;}
		}
		if(A[i]!=p){p=A[i];l=0;}++i;
		if(++l>k||a>>31||b>>31){printf("NO\n");return 0;}
	}
	printf("%s\n",A);
	return 0;
}
