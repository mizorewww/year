/* Codeforces 493A - Vasya and Football
 * https://codeforces.com/problemset/problem/493/A
 * rating: 1300 | tags: implementation
 * source: accepted submission #8955598 (GNU C) downloaded from Codeforces
 */

#include<stdio.h>
#include<string.h>

char as[100], ar[100], te[100];
int t1[100], t2[100];

int main()
{
	int i, j, k, n, a, b, c;
	char c1,c2;
	scanf(" %s %s",ar,as);

	scanf(" %d",&n);

	for(i=0;i<n;i++)
	{
		scanf(" %d %c %d %c",&a,&c1,&b,&c2);
		if(c1=='h')
		{
			if(t1[b]>=2) continue;
			if(c2=='y') t1[b]++; else t1[b]+=2;
			if(t1[b]>=2) printf("%s %d %d\n",ar,b,a);
		}
		else
		{
			if(t2[b]>=2) continue;		
			if(c2=='y') t2[b]++; else t2[b]+=2;
			if(t2[b]>=2) printf("%s %d %d\n",as,b,a);		
		}
	
	}

	return 0;
}
