/* Codeforces 1635B - Avoid Local Maximums
 * https://codeforces.com/problemset/problem/1635/B
 * rating: 800 | tags: greedy
 * source: accepted submission #147070599 (GNU C11) downloaded from Codeforces
 */

#include <stdio.h>
int main()
{
	int T,n,i,a[300000],p;
	scanf("%d",&T);
	while (T--){
		scanf("%d",&n);
		p=0;
		for (i=1;i<=200000;i++)
			a[i]=0;
		for (i=1;i<=n;i++)
			scanf("%d",&a[i]);
		for (i=2;i<=n-1;i++)
			if ((a[i]>a[i-1])&&(a[i]>a[i+1])){
				a[i+1]=a[i]>a[i+2]?a[i]:a[i+2];
				p++;
			}
		printf("%d\n",p);
		for (i=1;i<=n-1;i++)
			printf("%d ",a[i]);
		printf("%d\n",a[i]);
	}
	 
}
