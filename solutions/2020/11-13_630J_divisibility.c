/* Codeforces 630J - Divisibility
 * https://codeforces.com/problemset/problem/630/J
 * rating: 1100 | tags: math, number theory
 * source: accepted submission #16164379 (GNU C) downloaded from Codeforces
 */

#include<stdio.h>
int main(){
    unsigned long long inp = 0, res = 0;
	scanf("%llu", &inp);
	int x = 8 * 9 * 5*7;
	printf("%llu", inp / x);
	return 0;
}
