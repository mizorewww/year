/* Codeforces 378A - Playing with Dice
 * https://codeforces.com/problemset/problem/378/A
 * rating: 800 | tags: brute force
 * source: accepted submission #5555057 (GNU C) downloaded from Codeforces
 */

#include <stdio.h>
void za(int *a){if(*a<0)*a*=-1;}
int main(){
int a,b,kkk,c=0,d=0,i=0,j,k=0,l,m,n,ans,s,v;
scanf("%d%d",&n,&m);

for(i=1;i<7;i++){
a=n-i;
za(&a);
b=m-i;
za(&b);
if(a>b)c++;
else if(a<b)k++;
else d++;
}
printf("%d %d %d",k,d,c);
return 0;
}
