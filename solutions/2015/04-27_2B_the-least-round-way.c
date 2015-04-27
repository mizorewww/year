/* Codeforces 2B - The least round way
 * https://codeforces.com/problemset/problem/2/B
 * rating: 2000 | tags: dp, math
 * source: accepted submission #19653730 (GNU C) downloaded from Codeforces
 */

#include<stdio.h>

#include <math.h>

int pow2(unsigned long int a,int n)

{

	int c=0;

	while(a%n==0&&a!=0)

	{

		c++;

		a/=n;

	}

	return c;

}

int main()

{

	unsigned long int a[1000][1000];

	int two[1000][1000];

	char c[1000][1000];char d[1000][1000];

	char cc2[2000];

	

	

	int n,i,j,l2=0,l5=0,k,flag=0,b,m,flag2=0;

	scanf(" %d",&n);

	for(i=0;i<n;i++)

	for(j=0;j<n;j++)

	 {

	 scanf(" %lu",&a[i][j]);

	 if(a[i][j]==0)

	   {

	   flag=1;

	   b=i;

	   m=j;}

	   

     }

	

	

	

	

	 for(i=0;i<n;i++)

	 {

	 	for(j=0;j<n;j++)

	 	{

	 		two[i][j]=pow2(a[i][j],2);

	 		

	 		

	 	}

	 }

	

	 for(j=1;j<n;j++)

	 {

	 	two[0][j]+=two[0][j-1];

	 	c[0][j]='R';



	 }

	 for(i=1;i<n;i++)

	 {

	 	

	 	two[i][0]+=two[i-1][0];

	 	c[i][0]='D';

	 }

	 

	 for(i=1;i<n;i++)

	 {

	 	for(j=1;j<n;j++)

	 	{

	 		if(two[i][j-1]<two[i-1][j])

	 		{

	 			two[i][j]+=two[i][j-1];

	 			

	 			 

	 			c[i][j]='R';

	 		}

	 		else

	 		{

	 		two[i][j]+=two[i-1][j];

	 		 c[i][j]='D';

	      }

	 	}

	 }

	 

	  

	  l2=two[n-1][n-1];

	 

	  

	 for(i=0;i<n;i++)

	 {

	 	for(j=0;j<n;j++)

	 	{

	 		two[i][j]=pow2(a[i][j],5);

	 		

	 		

	 	}

	 }

	 for(j=1;j<n;j++)

	 {

	 	two[0][j]+=two[0][j-1];

	 	d[0][j]='R';

	 }

	 for(i=1;i<n;i++)

	 {

	 	two[i][0]+=two[i-1][0];

	 		d[i][0]='D';

	 }

	 for(i=1;i<n;i++)

	 {

	 	for(j=1;j<n;j++)

	 	{

	 		if(two[i][j-1]<two[i-1][j])

	 		{

	 			

	 			two[i][j]+=two[i][j-1];

	 			d[i][j]='R';

	 		}

	 		else

	 	{

	 		two[i][j]+=two[i-1][j];

	 		d[i][j]='D';

	 	}

	 	}

	 }

	 l5=two[n-1][n-1];

	

	

	if((l2<l5&&flag==0)||(l2==0))

	{ printf("%d\n",l2);flag2=1;

		k=0;

		i=n-1;j=n-1;

		while(!(i==0&&j==0))

		{

			cc2[k]=c[i][j];

			if(c[i][j]=='R')

			 j--;

			 else

			 i--;

			 k++;

		}

		for(j=k-1;j>=0;j--)

	{

		printf("%c",cc2[j]);

	}

	l2=0;l5=0;

	}

	 else if((l5<=l2&&flag==0)||l5==0)

	 {printf("%d\n",l5);

	 flag2=1;

		k=0;

		i=n-1;j=n-1;

		while(!(i==0&&j==0))

		{

			cc2[k]=d[i][j];

			if(d[i][j]=='R')

			 j--;

			 else

			 i--;

			 k++;

		}

		for(j=k-1;j>=0;j--)

	{

		printf("%c",cc2[j]);

	}

	l2=0;l5=0;

	}

	

  

  if(flag==1&&flag2==0)

  {

     printf("1\n");

     for(i=0;i<b;i++)

     printf("D");

     for(i=0;i<m;i++)

     printf("R");

     for(i=1;i<=n-1-b;i++)

     printf("D");

	 for(i=1;i<=n-1-m;i++)

	 printf("R"); 

  	

  }

  

  return 0;

}
