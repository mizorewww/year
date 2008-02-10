/* Codeforces 282C - XOR and OR
 * https://codeforces.com/problemset/problem/282/C
 * rating: 1500 | tags: constructive algorithms, implementation, math
 * source: accepted submission #3306960 (GNU C) downloaded from Codeforces
 */

#include<stdio.h>
#include<string.h>
int main()
{
	char a[1000001],b[1000001];
	int count1=0,count2=0,i,j;
	scanf("%s%s",a,b);
	for(i=0;a[i]!='\0';i++)
		if(a[i]=='0')
			count1++;
	j=i;
	for(i=0;b[i]!='\0';i++)
		if(b[i]=='0')
			count2++;
	if(i!=j)
	{
		printf("NO\n");
	return 0;
	}
	if(count1==j && count2==i)
		printf("YES\n");
	else if(count1==j)
		printf("NO\n");
	else if(count2==i)
		printf("NO\n");
	else
		printf("YES\n");
	return 0;
}
