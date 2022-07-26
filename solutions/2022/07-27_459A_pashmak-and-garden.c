/* Codeforces 459A - Pashmak and Garden
 * https://codeforces.com/problemset/problem/459/A
 * rating: 1200 | tags: implementation
 * source: accepted submission #20810446 (GNU C11) downloaded from Codeforces
 */

#include<stdio.h>
int main()
{
	int x,y,z,w;
	scanf("%d%d%d%d",&x,&y,&z,&w);
	if(x==z)
	{
		printf("%d %d %d %d",x+w-y,y,x+w-y,w);
	}

	else if(y==w)
	{
		printf("%d %d %d %d",x,z+y-x,z,z+y-x);
	}
	else if((x-z)==(y-w) || (x-z)==(w-y)) 
	{
		printf("%d %d %d %d",z,y,x,w);
	}
	else printf("-1");
	return 0;
}
