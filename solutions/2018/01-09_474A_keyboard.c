/* Codeforces 474A - Keyboard
 * https://codeforces.com/problemset/problem/474/A
 * rating: 900 | tags: implementation
 * source: accepted submission #18987630 (GNU C) downloaded from Codeforces
 */

#include<stdio.h>

int main()

{

char a,b[101],c[31]="qwertyuiopasdfghjkl;zxcvbnm,./";

int f=1,i,d[123];

scanf("%c%s",&a,b);

for(i=0;i<30;i++)

d[(int)c[i]]=i;

if(a=='R')

f=-1;

for(i=0;b[i];i++)

printf("%c",c[d[(int)b[i]]+f]);

}
