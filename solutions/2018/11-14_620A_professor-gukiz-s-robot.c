/* Codeforces 620A - Professor GukiZ's Robot
 * https://codeforces.com/problemset/problem/620/A
 * rating: 800 | tags: implementation, math
 * source: accepted submission #15476423 (GNU C) downloaded from Codeforces
 */

#include <stdio.h>
#include <stdlib.h>
int main() {
int a,b,x,y,s;
scanf("%d%d%d%d",&a,&b,&x,&y);
s=(abs(a-x)>abs(b-y))?abs(a-x):abs(b-y);
printf("%d",s);}
