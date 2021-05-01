/* Codeforces 1282B1 - K for the Price of One (Easy Version)
 * https://codeforces.com/problemset/problem/1282/B1
 * rating: 1400 | tags: dp, greedy, sortings
 * source: accepted submission #67552313 (GNU C11) downloaded from Codeforces
 */

#include<stdio.h>
#include<stdlib.h>
int cmp(const void *a,const void *b)
{
    return *(int *)a-*(int *)b;
}
int main()
{
	int t,n,p,k,i,j,m,s;
	int a[200000]={0};
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		scanf("%d %d %d",&n,&p,&k);
		s=p;
		for(j=0;j<n;j++)
		{
			scanf("%d",&a[j]);
		}
		qsort(a,n,sizeof(a[0]),cmp);
		for(j=1;j<n;j=j+2)
		{
			if(p<a[j]) break;
			p=p-a[j];
		}
		if(j-1<n&&p>=a[j-1]) j=j;
		else j=j-1;
		for(m=0;m<n;m=m+2)
		{
			if(s<a[m]) break;
			s=s-a[m];
		}
		if(m-1<n&&s>=a[m-1]) m=m;
		else m=m-1;
		if(m>j) j=m;
		printf("%d\n",j);
	}
	return 0;
}
