/* Codeforces 550E - Brackets in Implications
 * https://codeforces.com/problemset/problem/550/E
 * rating: 2200 | tags: constructive algorithms, greedy, implementation, math
 * source: accepted submission #11431864 (GNU C) downloaded from Codeforces
 */

#include<stdio.h>
char fast_char_var;
#define	fast_unsigned_dtype	unsigned long
fast_unsigned_dtype fast_unsigned_var;
fast_unsigned_dtype fast_unsigned()
{
	fast_char_var=getchar();
	while(fast_char_var<48||fast_char_var>57)
		fast_char_var=getchar();
	fast_unsigned_var=0;
	while(fast_char_var>47&&fast_char_var<58)
	{
		fast_unsigned_var=(fast_unsigned_var<<1)+(fast_unsigned_var<<3)+fast_char_var-48;
		fast_char_var=getchar();
	}
	return fast_unsigned_var;
}
int main()
{
	unsigned long n,i,x,a[100005],count=0,flag=0,s=0;
	static char string[10000007];
	n=fast_unsigned();
	for(i=1;i<=n;i++)
	{
		a[i]=fast_unsigned();
	}
	if(a[n])
	{
		printf("NO\n");
		return 0;
	}
	if(n==2&&a[1]==0)
	{
		printf("NO\n");
		return 0;
	}
	if(a[1])
	{
		if(a[2]!=0)
		{
			string[s++]='(';
			string[s++]='1';
			for(i=2;i<=n;i++)
			{
				if(a[i]==0)
					break;
				else
				{
					string[s++]='-';
					string[s++]='>';
					string[s++]='1';
				}
			}
			string[s++]=')';
		}
		else
		{
			string[s++]='1';
			i=2;
		}
		string[s++]='-';
		string[s++]='>';
		string[s++]='0';
		i++;
	}
	else
	{
		string[s++]='0';
		i=2;
	}
	if(i>n)
	{
		string[s++]=0;
		printf("YES\n%s\n",string);
		return 0;
	}
	else if(i==n)
	{
		printf("NO\n");
		return 0;
	}
	else
	{
		string[s++]='-';
		string[s++]='>';
		if(i+1!=n)
		{
			string[s++]='(';
			string[s++]=a[i]+'0';
			i++;
			for(;i<n;i++)
			{
				string[s++]='-';
				string[s++]='>';
				string[s++]=a[i]+'0';
			}
			string[s++]=')';
		}
		else
		{
			string[s++]=a[i]+'0';
			i++;
		}
		string[s++]='-';
		string[s++]='>';
		string[s++]='0';
		string[s++]=0;
		printf("YES\n%s\n",string);
	}
	return 0;
}
