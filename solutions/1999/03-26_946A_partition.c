/* Codeforces 946A - Partition
 * https://codeforces.com/problemset/problem/946/A
 * rating: 800 | tags: greedy
 * source: accepted submission #36014419 (GNU C) downloaded from Codeforces
 */

#include<stdio.h>
int main(){
int n,a,r=0,t=0;
scanf("%d",&n);
while(n--){
scanf("%d",&a);
if(a<0)
r+=a;
else
t+=a;
}
printf("%d\n",t-r);


return 0;
}
