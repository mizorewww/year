/* Codeforces 1562A - The Miracle and the Sleeper
 * https://codeforces.com/problemset/problem/1562/A
 * rating: 800 | tags: greedy, math
 * source: accepted submission #127062219 (GNU C11) downloaded from Codeforces
 */

#include <stdio.h>

int main(void) {
	int testcase;
	scanf("%d",&testcase);
	
	while(testcase--){
		int a,b;
		scanf("%d %d",&a,&b);
		
		if(b/2 < a) printf("%d\n", b-a);
		else printf("%d\n",(b+1)/2-1);
	}
}
