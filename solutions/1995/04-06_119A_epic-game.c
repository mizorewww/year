/* Codeforces 119A - Epic Game
 * https://codeforces.com/problemset/problem/119/A
 * rating: 800 | tags: implementation
 * source: accepted submission #759683 (GNU C) downloaded from Codeforces
 */

#include<stdio.h>

int gcd(int a,int b) {
	return b?gcd(b,a%b):a;
}

int main() {
	int a,b,n;
	scanf("%d %d %d",&a,&b,&n);
	while(1) {
		if (!n) {
			puts("1");
			break;
		}
		n-=gcd(n,a);
		if (!n) {
			puts("0");
			break;
		}
		n-=gcd(n,b);
	}
	return 0;
}
