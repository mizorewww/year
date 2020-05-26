/* Codeforces 223B - Two Strings
 * https://codeforces.com/problemset/problem/223/B
 * rating: 1900 | tags: data structures, dp, strings
 * source: accepted submission #2197411 (GNU C) downloaded from Codeforces
 */

#include<stdio.h>

int main()
{
int i,j,k,ans,j1,m;
char a[200004],b[200004];
int c[30]={0};

scanf("%s",a);
scanf("%s",b);

for(i=0;i<30;i++)
	c[i]=-1;

j=0;
j1=0;

for(i=0;a[i];i++)
{
m=0;
if(a[i]==b[j])
	{
	c[b[j]-'a']=j;
	j++;
	m=1;
	}
if(a[i]==b[j1])
	{
	j1++;
	m=1;
	}

//printf("M%d %d %d\n",j,j1,c[a[i]-'a']);

if(c[a[i]-'a']==-1)
	break;

if(m==0)
	{
	if(j1>(c[a[i]-'a']+1))	
		j1=c[a[i]-'a']+1;
	}
//printf("%d %d\n",j,j1);
}

ans=1;
if(b[j]||b[j1]||a[i])
	ans=0;


if(ans==0)
	printf("No\n");
else
	printf("Yes\n");

return 0;
}
