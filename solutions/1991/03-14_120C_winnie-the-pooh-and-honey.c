/* Codeforces 120C - Winnie-the-Pooh and honey
 * https://codeforces.com/problemset/problem/120/C
 * rating: 1100 | tags: implementation, math
 * source: accepted submission #777317 (GNU C) downloaded from Codeforces
 */

#include <stdio.h>

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n, k;
	int ans = 0;
	scanf("%d%d", &n, &k);
	while(n--){
		int honey;
		scanf("%d", &honey);
		int times;
		for(times=0;times<3;times++)
			if(honey >= k)
				honey -= k;
		ans += honey;
	}
	printf("%d\n", ans);
	return 0;
}
