/* Codeforces 682B - Alyona and Mex
 * https://codeforces.com/problemset/problem/682/B
 * rating: 1200 | tags: sortings
 * source: accepted submission #20428749 (GNU C) downloaded from Codeforces
 */

#include<stdio.h>

int cmp(const void *c,const void *b)

{

	return (*(int*)c-*(int*)b);

}



int main()

{

	int n,a[100005],i,j=1;

	scanf("%d",&n);

	for(i=0;i<n;i++)

		scanf("%d",&a[i]);

	qsort(a,n,sizeof(int),cmp);

	for(i=0;i<n;i++)

	{	

		if(a[i]>=j)

		{

			a[i]=j;

			j++;

		}

	}

	printf("%d\n",j);

	return 0;

}
