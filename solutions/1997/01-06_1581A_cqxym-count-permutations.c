/* Codeforces 1581A - CQXYM Count Permutations
 * https://codeforces.com/problemset/problem/1581/A
 * rating: 800 | tags: combinatorics, math, number theory
 * source: accepted submission #130358921 (GNU C11) downloaded from Codeforces
 */

#include<stdio.h>
int main(){
int test;
scanf("%d",&test);
while(test--){
int num;
scanf("%d",&num);
long long int f=1;
for(int k=3;k<=2*num;k++){
f=(f*k)%1000000007;
}
printf("%d\n",f);
}
return 0;
}
