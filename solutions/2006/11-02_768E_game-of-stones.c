/* Codeforces 768E - Game of Stones
 * https://codeforces.com/problemset/problem/768/E
 * rating: 2100 | tags: bitmasks, dp, games
 * source: accepted submission #24843899 (GNU C) downloaded from Codeforces
 */

#include<stdio.h>
#include<stdlib.h>
typedef long long unsigned llu;
typedef unsigned u;
typedef struct S{struct S*nx[2];u val;}v;
v*alloc()
{
	v*x;
	x=(v*)malloc(sizeof(v));
	x->nx[0]=x->nx[1]=NULL;
	x->val=0;
	return x;
}
v G[66];
u F(u n,llu b)
{
	u i;v*p;llu x=b;
	for(p=G+n;x;x>>=1)
	{
		if(p->nx[x&1]==NULL)
		p->nx[x&1]=alloc();
		p=p->nx[x&1];
	}
	if(p->val)return p->val-1;
	for(i=0;++i<=n;)if(!(b&(1llu<<(i-1))))
	x|=1llu<<F(n-i,(b^(1llu<<(i-1)))&((1llu<<(n-i))-1));
	for(i=-1;x&(1llu<<++i););
	p->val=i+1;
	return i;
}
u R[66];
int main()
{
	u i,j,k=0;
	for(i=66;i--;)R[i]=F(i,0);
	for(scanf("%u",&j);j--;k^=R[i])scanf("%u",&i);
	printf(k?"NO\n":"YES\n");
	return 0;
}
