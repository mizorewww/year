/* Codeforces 1003C - Intense Heat
 * https://codeforces.com/problemset/problem/1003/C
 * rating: 1300 | tags: brute force, implementation, math
 * source: accepted submission #39924969 (GNU C) downloaded from Codeforces
 */

#include<stdio.h>
int main()
{
	int i,n,k;
	double max=0;
	int a[5005];
	scanf("%d%d",&n,&k);
	for(i=0;i<n;i++)
		scanf("%d",a+i);
	for(i=1;i<n;i++)
		a[i]+=a[i-1];
	
	while(k<=n)
	{
		if(max<a[k-1]*1.0/k)
			max=a[k-1]*1.0/k;
		for(i=k;i<n;i++)
			if(max<(a[i]-a[i-k])*1.0/k)
				max=(a[i]-a[i-k])*1.0/k;
		k++;
	}
	printf("%.15lf",max);
	return 0;
}
