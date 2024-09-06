/* Codeforces 660A - Co-prime Array
 * https://codeforces.com/problemset/problem/660/A
 * rating: 1200 | tags: greedy, implementation, math, number theory
 * source: accepted submission #18338417 (GNU C) downloaded from Codeforces
 */

#include<stdio.h>





int ucln(int a,int b)

{

	int temp;

	while(b>0)

	{

		temp=a%b;

		a=b;

		b=temp;

	}

	return a;

}



int main()

{

	int n;

	scanf("%d",&n);

	long a[n+n];

	int i=1;

	int j=1;

	scanf("%ld",&a[0]);

	while(i<n)

	{

		scanf("%ld",&a[j]);

		if(ucln(a[j-1],a[j])!=1)

		{

			a[j+1]=a[j];

			a[j++]=1;

		} 

		j++;

		i++;

	}

	printf("%d\n",j-n);

	for(i=0;i<j;i++)

	{

		printf("%ld ",a[i]);

	}

}
