/* Codeforces 743B - Chloe and the sequence 
 * https://codeforces.com/problemset/problem/743/B
 * rating: 1200 | tags: binary search, bitmasks, constructive algorithms, implementation
 * source: accepted submission #22959738 (GNU C) downloaded from Codeforces
 */

#include<stdio.h>

int main(void)
{
	long long n, k;
	scanf("%I64d %I64d", &n, &k);
	n = 1;
	while (k % 2 == 0){
		k /= 2;
		n++;
	}
	printf("%I64d", n);
}
