/* Codeforces 614B - Gena's Code
 * https://codeforces.com/problemset/problem/614/B
 * rating: 1400 | tags: implementation, math
 * source: accepted submission #15360750 (GNU C) downloaded from Codeforces
 */

#include<stdio.h>
typedef unsigned u;
char X[111111],Y[111111],*A,*B;
int main()
{
	u n,z=0,O,Z,H,i;A=X;
	for(scanf("%u",&n);n--;)
	{
		scanf("%s",A);
		O=Z=H=0;
		for(i=-1;A[++i];)if(A[i]=='1')++O;
		else if(A[i]=='0')++Z;
		else ++H;
		if(H||O>1){B=A;A=Y;}
		else if(!O){printf("0\n");return 0;}
		else z+=Z;
	}
	if(B)printf("%s",B);
	else putchar('1');
	while(z--)putchar('0');
	putchar('\n');
	return 0;
}
