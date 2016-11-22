/* Codeforces 165A - Supercentral Point
 * https://codeforces.com/problemset/problem/165/A
 * rating: 1000 | tags: implementation
 * source: accepted submission #1363050 (GNU C) downloaded from Codeforces
 */

#include<stdio.h>
int main()
{
	int n,i,j,f,count=0,A[2000],B[2000],a,b,c,d;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d%d",&A[i],&B[i]);
	for(i=0;i<n;i++)
	{
			a=0,b=0,c=0,d=0;
		for(j=0;j<n;j++)
		{
			if(A[i]==A[j] && B[i]>B[j])
				a++;
			if(A[i]==A[j] && B[i]<B[j])
				b++;
			if(A[i]<A[j] && B[i]==B[j])
				c++;
			if(A[i]>A[j] && B[i]==B[j])
				d++;
		}
		if(a>0 && b>0 && c>0 && d>0)
			count++;
	}
	printf("%d",count);
	return 0;
}
