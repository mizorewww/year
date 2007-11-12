/* Codeforces 1312D - Count the Arrays
 * https://codeforces.com/problemset/problem/1312/D
 * rating: 1700 | tags: combinatorics, math
 * source: accepted submission #72819694 (GNU C11) downloaded from Codeforces
 */

#include<stdio.h>
const int m = 998244353;

int power( int x, int y ) {
	int a = 1;
	for( ; y>0; y>>=1, x=1ll*x*x %m )
		if( y&1 )
			a = 1ll*a*x %m;
	return a;
}

int fact( int n ) {
	int f = 1;
	for( int i=2; i<=n; ++i )
		f = 1ll*f*i %m;
	return f;
}

int main() {
	int N, M;
	scanf("%d%d", &N, &M);
	if( N == 2 ) { printf("0\n", M); return 0; }
	int ans = 1ll*(N-2)*power(2, N-3) %m;
	ans = 1ll*ans*fact(M) %m;
	ans = 1ll*ans*power(fact(M-N+1), m-2) %m;
	ans = 1ll*ans*power(fact(N-1), m-2) %m;
	printf("%d\n", ans);

}
