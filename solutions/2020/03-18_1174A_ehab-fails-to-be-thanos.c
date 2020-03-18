/* Codeforces 1174A - Ehab Fails to Be Thanos
 * https://codeforces.com/problemset/problem/1174/A
 * rating: 1000 | tags: constructive algorithms, greedy, sortings
 * source: accepted submission #55026039 (GNU C11) downloaded from Codeforces
 */

#include<stdio.h>
#include<stdlib.h>
int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}
int main()
{
	int n,a[2000],i,sum1=0,sum2=0;
	scanf("%d",&n);
	for(i=0;i<2*n;i++)scanf("%d",&a[i]);
	
	qsort(a,2*n,sizeof(int),cmpfunc);
	for(i=0;i<n;i++)
	{
		sum1+=a[i];
		sum2+=a[i+n];
	}
	if(sum1==sum2)printf("-1");
	else
	{
		for(i=0;i<2*n;i++) printf("%d ",a[i]);
	}
}
