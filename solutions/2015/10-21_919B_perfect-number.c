/* Codeforces 919B - Perfect Number
 * https://codeforces.com/problemset/problem/919/B
 * rating: 1100 | tags: binary search, brute force, dp, implementation, number theory
 * source: accepted submission #34742840 (GNU C) downloaded from Codeforces
 */

#include<stdio.h>
int n,i,c;
int f(int n){
	if(n==0)return 0;
	return n%10+f(n/10);
}
int main(){
	scanf("%d",&n);
	while(1){
		i++;
		if(f(i)==10)c++;
		if(c==n){
			printf("%d",i);
			return 0;
		}
	}
}
