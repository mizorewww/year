/* Codeforces 810B - Summer sell-off
 * https://codeforces.com/problemset/problem/810/B
 * rating: 1300 | tags: greedy, sortings
 * source: accepted submission #27245360 (GNU C) downloaded from Codeforces
 */

#include<stdio.h>
#include<stdlib.h>

#define ll long long int

int cmpfnc(const void * a, const void * b)
{
	   return ( *(int*)b - *(int*)a );
}

int min(int a,int b)
{
	if(a<b)
		return a;
	return b;
}

int main()
{
	int n,f ;
	scanf("%d %d",&n,&f);
	int i;
	int arr[100005];
	ll total = 0 ;
	for(i=0;i<n;i++)
	{
		int a,b;
		scanf("%d %d",&a,&b);
		total += (ll)min(a,b) ;
		arr[i] = min(2*a,b)-min(a,b) ;
	}
	qsort(arr,n,sizeof(int),cmpfnc);
/*
	for(i=0;i<n;i++)
		printf("%d ",arr[i]);
	printf("\n");
*/
	for(i=0;i<f;i++)
		total+=(ll)arr[i];

	printf("%lld\n",total);

	return 0;
}
