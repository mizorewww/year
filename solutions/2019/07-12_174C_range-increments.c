/* Codeforces 174C - Range Increments
 * https://codeforces.com/problemset/problem/174/C
 * rating: 1800 | tags: data structures, greedy
 * source: accepted submission #1502706 (GNU C) downloaded from Codeforces
 */

#include<stdio.h>

int n;
int stack[100010],top=0;
int output[100010][2],nout=0;

int main()
{
	int i,j,trnt,prev=0;

	scanf("%d",&n);
	for (i=0;i<=n;i++)
	{
		if (i<n) { scanf("%d",&trnt); } else { trnt=0; }
		if (trnt==prev) { continue; }
		if (prev<trnt)
		{
			for (j=prev;j<trnt;j++) { stack[top++]=i; }
		}
		if (trnt<prev)
		{
			for (j=prev;j>trnt;j--)
			{
				output[nout][0]=stack[top-1]+1;
				output[nout][1]=i;
				nout++;
				top--;
			}
		}
		prev=trnt;
	}

	printf("%d\n",nout);
	for (i=0;i<nout;i++) { printf("%d %d\n",output[i][0],output[i][1]); }

	return 0;
}
