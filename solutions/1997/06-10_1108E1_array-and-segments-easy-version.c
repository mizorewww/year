/* Codeforces 1108E1 - Array and Segments (Easy version)
 * https://codeforces.com/problemset/problem/1108/E1
 * rating: 1800 | tags: brute force, greedy, implementation
 * source: accepted submission #48836495 (GNU C11) downloaded from Codeforces
 */

#include<stdio.h>

int n, m;
int a[100005];
int s[301][2];

int acc[100005];

int main() {
	scanf("%d%d", &n, &m);
	for( int i=0; i<n; ++i )
		scanf("%d", a+i);
	for( int i=0; i<m; ++i )
		scanf("%d%d", &s[i][0], &s[i][1] );
	int ans = -1, ansi, ansc;
	for( int i=0; i<n; ++i )
	{
		for( int j=0; j<n; ++j )
			acc[j] = 0;
		int cc = 0;
		for( int j=0; j<m; ++j )
			if( (s[j][0]-1) > i || (s[j][1]-1) < i )
				acc[s[j][0]-1]--, acc[s[j][1]]++, ++cc;
		for( int j=0, x=0; j<n; ++j )
			x += acc[j],
			acc[j] = x;
		int cans = -1;
		for( int j=0; j<n; ++j ) {
			if( a[i] - (acc[j]+a[j]) > cans )
				cans = a[i] - (acc[j]+a[j]);
		}
		// printf("sex: %d %d\n", i, cans);
		if( ans < cans ) {
			ans = cans;
			ansi = i;
			ansc = cc;
		}
	}
	printf("%d\n%d\n", ans, ansc);
	for( int j=0; j<m; ++j )
		if( (s[j][0]-1) > ansi || (s[j][1]-1) < ansi )
			printf("%d ", j+1);
	printf("\n");
}
