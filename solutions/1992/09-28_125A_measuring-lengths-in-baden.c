/* Codeforces 125A - Measuring Lengths in Baden
 * https://codeforces.com/problemset/problem/125/A
 * rating: 1400 | tags: math
 * source: accepted submission #816787 (GNU C) downloaded from Codeforces
 */

#include<stdio.h>
int main()
{
	int n,a,b;
	scanf("%d",&n);
	a=n/36;
	b=(n%36)/3;
	if((n%36)%3==2) b++;
	if(b==12)
	{
		a++;
		b=0;
	}
	printf("%d %d\n",a,b);
	return 0;
}
