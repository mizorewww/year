/* Codeforces 149A - Business trip
 * https://codeforces.com/problemset/problem/149/A
 * rating: 900 | tags: greedy, implementation, sortings
 * source: accepted submission #19902665 (GNU C) downloaded from Codeforces
 */

#include<stdio.h>

int a[13],x,i,j,s,t,k;

int main(){

	scanf("%d",&k);

	for(i=0;i<12;i++){

		scanf("%d",&x);

		for(j=i;j && x<a[j-1];j--)

			a[j] = a[j-1];

		a[j] = x;

	}

	for(i=12;i>=0;i--)

	{

		t+=a[i];

		if(t>=k)

		{

			printf("%d",s);

			return 0;

		}

		s++;

	}

	printf("-1");

	return 0;

}
