/* Codeforces 732D - Exams
 * https://codeforces.com/problemset/problem/732/D
 * rating: 1700 | tags: binary search, greedy, sortings
 * source: accepted submission #21655462 (GNU C) downloaded from Codeforces
 */

#include<stdio.h> 

int n,m;

int a[100100],b[100100],c[100100];

int check(int k);

int main()

{

	int i,mi=0,mid,f,e,ans=-1;

	scanf("%d%d",&n,&m);

	for(i=1;i<=n;i++)

		scanf("%d",&a[i]);

	for(i=1;i<=m;i++)

	{

		scanf("%d",&b[i]);

		c[i]=0;

	}

	f=1;e=n+1;

	mid=(f+e)/2;

	while(mi!=mid)

	{

		if(check(mid))

		{

			e=mid;

			ans=mid;

		}

		else

			f=mid;

		mi=mid;

		mid=(f+e)/2;

	}

	printf("%d",ans);

	return 0;

}





int check(int k)

{

	int i,s=0,j;

	for(i=k;i>0;i--)

	{

		if(c[a[i]]||!a[i])

		{

			if(s)

				s--;

		}

		else

		{

			c[a[i]]=1;

			s+=b[a[i]];

		}

	}

	for(i=1;i<=m;i++)

	{

		if(!c[i])

			s=1;

		c[i]=0;

	}

	

	if(s>0)

		return 0;

	else

		return 1;

}
