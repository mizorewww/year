/* Codeforces 282A - Bit++
 * https://codeforces.com/problemset/problem/282/A
 * rating: 800 | tags: implementation
 * source: accepted submission #18820711 (GNU C) downloaded from Codeforces
 */

#include<stdio.h>

int main()

{

int m,n,i=1,x=0;

scanf("%d",&m);

for(i=1;i<=m;i++)

{

char ch[4];

scanf("%s",&ch);

if(ch[1]=='+')

x=x+1;

else

x=x-1;

}

printf("%d",x);

}
