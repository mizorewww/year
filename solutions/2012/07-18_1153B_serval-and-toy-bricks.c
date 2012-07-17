/* Codeforces 1153B - Serval and Toy Bricks
 * https://codeforces.com/problemset/problem/1153/B
 * rating: 1200 | tags: constructive algorithms, greedy
 * source: accepted submission #52700984 (GNU C11) downloaded from Codeforces
 */

#include<stdio.h>
#define N 101
int Min(int a,int b)
{
	if(a<b)
		return a;
	return b;
}
int main()
{
	int i,j,r,c,h,cmax[N],rmax[N],top[N][N];
	scanf("%d%d%d",&r,&c,&h);
	for(i=0;i<c;i++)
		scanf("%d",&cmax[i]);
	for(i=0;i<r;i++)
		scanf("%d",&rmax[i]);
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			scanf("%d",&top[i][j]);
			top[i][j]*=Min(cmax[j],rmax[i]);
			printf("%d ",top[i][j]);
		}
		printf("\n");
	}
	return 0;
}
