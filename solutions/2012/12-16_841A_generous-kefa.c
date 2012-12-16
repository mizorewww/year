/* Codeforces 841A - Generous Kefa
 * https://codeforces.com/problemset/problem/841/A
 * rating: 900 | tags: brute force, implementation
 * source: accepted submission #29567215 (GNU C) downloaded from Codeforces
 */

#include<stdio.h>
int main()
{
int n,k,i,j,count,ans=0;
scanf("%d %d",&n,&k);
char ar[n];
scanf("%s",ar);
for(i=0;i<n;i++)
{
count=0;
for(j=0;j<n;j++)
{
if(ar[i]==ar[j])
count++;
}
if(count>ans)
ans=count;
}
ans>k?printf("NO\n"):printf("YES\n");
return 0;

}
