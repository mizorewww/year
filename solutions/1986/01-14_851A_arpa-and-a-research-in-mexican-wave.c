/* Codeforces 851A - Arpa and a research in Mexican wave
 * https://codeforces.com/problemset/problem/851/A
 * rating: 800 | tags: implementation, math
 * source: accepted submission #30061221 (GNU C) downloaded from Codeforces
 */

#include <stdio.h>
int main(){
	int n, k, t;
	scanf("%d %d %d",&n,&k,&t);
	if(t<=k)
		printf("%d",t);
	else if(t<=n)
		printf("%d",k);
	else
		printf("%d",k-(t-n));
	return 0;
}
