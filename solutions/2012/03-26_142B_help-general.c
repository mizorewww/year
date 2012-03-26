/* Codeforces 142B - Help General
 * https://codeforces.com/problemset/problem/142/B
 * rating: 1800 | tags: constructive algorithms, greedy, implementation
 * source: accepted submission #1037707 (GNU C) downloaded from Codeforces
 */

#include <stdio.h>
int g(int n)
{
	if (n==1 || n==0) return n;
	else
		return 2;
}
int gao(int m, int n)
{
	if (n==1) return m;
	else if (n==2)
		return (m/4*2 + g(m%4)) * 2;
	else
		return (n * m + 1 ) / 2;

}
int main()
{
	int m, n, temp;
	while (~scanf("%d %d", &m, &n))
	{
		if (m<n)
		{
			temp = m;
			m = n; 
			n = temp;
		}
		printf("%d\n", gao(m, n));
	}
	return 0;
}
