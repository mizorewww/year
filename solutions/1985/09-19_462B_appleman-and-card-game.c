/* Codeforces 462B - Appleman and Card Game
 * https://codeforces.com/problemset/problem/462/B
 * rating: 1300 | tags: greedy
 * source: accepted submission #7595063 (GNU C) downloaded from Codeforces
 */

#include<stdio.h>
#include<string.h>
int compare(const void *a,const void *b) {
return (*(int*)b-*(int*)a); }
int main () {
long long int r,m,i,c,l=0;
scanf("%lld%lld",&r,&m);
char a[r+1];
int b[100];
memset(b,0,sizeof(b));
scanf("%s",a);
for(i=0;i<r;i++){ c=a[i]; b[c]++;}
qsort(b,100,sizeof(int),compare);
for(i=0;b[i]>0;i++) {
c=b[i];
if(c>m) c=m;
l=l+c*c;
m=m-c;
if(m==0) break;
}
printf("%lld\r",l);
return 0;
}
