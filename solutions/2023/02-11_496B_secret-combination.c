/* Codeforces 496B - Secret Combination
 * https://codeforces.com/problemset/problem/496/B
 * rating: 1500 | tags: brute force, constructive algorithms, implementation
 * source: accepted submission #9167729 (GNU C) downloaded from Codeforces
 */

#include<stdio.h>
typedef unsigned u;
u M[1111],T[1111],S[1111],*m,*t,*h;
int main()
{
	u n,x=0,y,z,i,j,k;char c;
	for(scanf("%u",&n);x<n;M[x]=9,S[x++]=c&15)
	while((c=getchar())<'0');
	m=M;t=T;
	for(x=0;x<n;++x)
	{
		for(i=x,j=k=y=0;j<n;++j,i=z)
		{
			t[j]=k;
			if(!y)
			{
				if(k<m[j])y=1;
				if(k>m[j])goto tj;
			}
			k+=S[z=((i==n-1)?0:i+1)]+10-S[i];
			if(k>=20)k-=20;
			else if(k>=10)k-=10;
		}
		h=t;t=m;m=h;
		tj:;
	}
	for(i=0;i<n;)putchar(m[i++]|'0');
	putchar('\n');
	return 0;
}
