/* Codeforces 1579A - Casimir's String Solitaire
 * https://codeforces.com/problemset/problem/1579/A
 * rating: 800 | tags: math, strings
 * source: accepted submission #130122315 (GNU C11) downloaded from Codeforces
 */

#include<stdio.h>
#include<string.h>
int main()
{
	char a[1000];
	int n,sum,x,j;
	scanf("%d\n",&n);
	for(int i=1;i<=n;i++)
	{sum=0;
	x=0;
	gets(a);
	for(j=0;a[j]!='\0';j++)
	{if(a[j]=='A'||a[j]=='C')
	sum++;
	else if(a[j]=='B')
	x++;}
	if(x==sum)
	printf("YES\n");
	else
	printf("NO\n");
	}
	return 0;
 }
