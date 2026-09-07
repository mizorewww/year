/* Codeforces 1486A - Shifting Stacks
 * https://codeforces.com/problemset/problem/1486/A
 * rating: 900 | tags: greedy, implementation
 * source: accepted submission #107853061 (GNU C11) downloaded from Codeforces
 */

#include<stdio.h>
int main()
{int a,b,c;
scanf("%d",&a);
for(b=0;b<a;b++)
{scanf("%d",&c);
long long sum=0;
int d,g[c+1],k=0;
for(d=0;d<c;d++)
{scanf("%d",&g[d]);

}
for(d=0;d<c;d++)
{sum=sum+g[d];
long long  i=d*(d+1)/2;
if(sum<i)
{printf("NO\n");
k=1;
break;
}
}
if(k==0)

printf("YES\n");
}
	
	
 }
