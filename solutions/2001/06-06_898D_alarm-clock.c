/* Codeforces 898D - Alarm Clock
 * https://codeforces.com/problemset/problem/898/D
 * rating: 1600 | tags: greedy
 * source: accepted submission #33304319 (GNU C) downloaded from Codeforces
 */

#include<stdio.h>
int main()
{
    int n,i,m,k,l=0,r=0,count=0,ans=0;
    scanf("%d%d%d",&n,&m,&k);
    int a[n+1],index[1000005]={0};
    for(i=0;i<n;i++)
    {
	scanf("%d",&a[i]);
	index[a[i]]=1;
    }
    while(r<1000003)
    {
	if(index[r]==1)
	{
	    count++;
	}
	if(count==k && r-l<m)
	{
	    index[r]=0;
	    count--;
	    ans++;
	}
	if(r-l==m-1)
	{
	    if(index[l]==1)
		count--;
	    l++;
	}
	r++;
    }
    printf("%d\n",ans);
    return 0;
}
