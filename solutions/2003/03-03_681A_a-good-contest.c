/* Codeforces 681A - A Good Contest
 * https://codeforces.com/problemset/problem/681/A
 * rating: 800 | tags: implementation
 * source: accepted submission #19590812 (GNU C) downloaded from Codeforces
 */

#include<stdio.h>

int main()

{

int i,n,a,b;

char s[11];

scanf("%d",&n);

for(i=1;i<=n;i++)

{

scanf("%s%d%d",s,&a,&b);

if(a>=2400 &&(b-a)>0)

{

printf("YES");

return 0;

}

}

printf("NO");

}
