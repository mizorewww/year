/* Codeforces 1149A - Prefix Sum Primes
 * https://codeforces.com/problemset/problem/1149/A
 * rating: 1200 | tags: constructive algorithms, greedy, math, number theory
 * source: accepted submission #53514689 (GNU C11) downloaded from Codeforces
 */

/*
1 3 4 6 7
1 2 3 5 7
2 3 5 6 7
2 3 5 6 7 8 9 10 11
*/
#include<stdio.h>
int main() {
	int a=0,b=0,n,d,i;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&d);
		if(d==1) a++; else b++;
	}
	if(b) {
		printf("2");
		b--;
		if(a) {
			printf(" 1");
			a--;
		}
	}
	else if(a) {
		printf("1");
		a--;
	}
	while(b--) {
		printf(" 2");
	}
	while(a--) {
		printf(" 1");
	}
	return 0;
}
