/* Codeforces 1025A - Doggo Recoloring
 * https://codeforces.com/problemset/problem/1025/A
 * rating: 900 | tags: implementation, sortings
 * source: accepted submission #41837252 (GNU C) downloaded from Codeforces
 */

#include<stdio.h>
int main()
{
	char a[100000];
	int c[26]={0},i,jud=0,n;
	scanf("%d",&n);
	scanf("%s",a);
	for(i=0;i<n;i++)
	{
		c[a[i]-'a']++;
		if(c[a[i]-'a']==2)
		{
			jud=1;
			break;
		}
	}
	if(n==1)jud=1;
	if(jud)printf("Yes");
	else printf("No");
	return 0;
}
