/* Codeforces 20B - Equation
 * https://codeforces.com/problemset/problem/20/B
 * rating: 2000 | tags: math
 * source: accepted submission #20931623 (GNU C) downloaded from Codeforces
 */

#include <stdio.h>
#include <math.h>
int main()
{
	double i,j,k,a,b,c;
	double ind,sum1,sum2;
	scanf("%lf %lf %lf",&a,&b,&c);
	ind=(b*b)-(4*a*c);

	if(a==0 && b==0 &&c==0)
	{
		printf("-1");
	}
	else if(a==0 && b==0 )
	{
		printf("0");

	}
	else if(a==0)
	{
		printf("1\n%lf",(-1*c)/b);


	}
	else if(ind>0)
	{
		sum1=((-1*b)+sqrt(ind))/(2*a);
		sum2=((-1*b)-sqrt(ind))/(2*a);
		printf("2\n");
		if(sum1<sum2){
			printf("%lf\n%lf",sum1,sum2);
		}
		else
		{
			printf("%lf\n%lf",sum2,sum1);
		}
	}
	else if(ind<0)
	{
		printf("0");

	}
	else if(ind==0)
	{
		sum1=(-1*b)/(2*a);
		printf("1\n%lf",sum1);
	}

	return 0;
}
