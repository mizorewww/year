/* Codeforces 652B - z-sort
 * https://codeforces.com/problemset/problem/652/B
 * rating: 1000 | tags: sortings
 * source: accepted submission #16923698 (GNU C) downloaded from Codeforces
 */

#include<stdio.h>
#include<stdlib.h>
int F(const void*x,const void*y){return*(int*)x-*(int*)y;}
int A[1111],n,i=-1,j=-1,k;
int main()
{
	for(scanf("%i",&n);++i<n;scanf("%i",A+i));
	qsort(A,n,sizeof(int),F);
	for(k=n;++j<=--k;)printf(j!=k?"%i %i ":"%i ",A[j],A[k]);
	putchar('\n');
	return 0;
}
