/* Codeforces 740B - Alyona and flowers
 * https://codeforces.com/problemset/problem/740/B
 * rating: 1200 | tags: constructive algorithms
 * source: accepted submission #22433291 (GNU C) downloaded from Codeforces
 */

#include<stdio.h>

int a[128],s[128];
int n,m;

int main() {
int i,l,r,ret=0;
scanf("%d %d",&n,&m);
for(i=0;i<n;i++) scanf("%d",&a[i]),s[i+1]=s[i]+a[i];
for(;m--;) {
scanf("%d %d",&l,&r);
if (s[r]>=s[l-1]) ret+=s[r]-s[l-1];
}
printf("%d\n",ret);
return 0;
}
