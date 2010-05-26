/* Codeforces 596A - Wilbur and Swimming Pool
 * https://codeforces.com/problemset/problem/596/A
 * rating: 1100 | tags: geometry, implementation
 * source: accepted submission #20375808 (GNU C) downloaded from Codeforces
 */

#include<stdio.h>



int main()

{

	int x0=1001,x1=-1001,y0=1001,y1=-1001;

	int n,x,y;

	scanf("%d",&n);

	for(;n>=1;n--)

	{

		scanf("%d",&x);

		if(x<x0) x0=x;

		if(x>x1) x1=x;

		scanf("%d",&y);

		if(y<y0) y0=y;

		if(y>y1) y1=y;

	}		

	x=x1-x0;

	y=y1-y0;

	int s=x*y;

	printf("%d",s==0?-1:s);

	return 0;

}
