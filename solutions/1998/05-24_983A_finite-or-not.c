/* Codeforces 983A - Finite or not?
 * https://codeforces.com/problemset/problem/983/A
 * rating: 1700 | tags: implementation, math
 * source: accepted submission #38288255 (GNU C11) downloaded from Codeforces
 */

#include<stdio.h>
long long gcd(long long a,long long b) {
	return b?gcd(b,a%b):a;
}
void solve() {
	long long p,q,b;
	scanf("%I64d",&p);
	scanf("%I64d",&q);
	scanf("%I64d",&b);
	long long gcd1=gcd(p,q);
	p/=gcd1;
	q/=gcd1;
	gcd1=gcd(q,b);
	while(gcd1!=1) {
		q/=gcd1;
		gcd1=gcd(q,gcd1);
	}
	if(q==1)puts("Finite");
	else puts("Infinite");
}
int main() {
	long long q;
	scanf("%I64d",&q);
	while(q--)solve();
	return 0;
}
