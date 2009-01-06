/* Codeforces 1612D - X-Magic Pair
 * https://codeforces.com/problemset/problem/1612/D
 * rating: 1600 | tags: math, number theory
 * source: accepted submission #136460333 (GNU C11) downloaded from Codeforces
 */

#include <stdio.h>
#include <stdbool.h>

typedef long long ll;

int main(){
	int t;
	scanf("%d", &t);
	for (int i = 1; i <= t; i++){
		ll a, b, x;
		scanf("%lld %lld %lld", &a, &b, &x);
		while (true){
			if (a == x || b == x){
				printf("YES\n");
				break;
			}
			if (a < x && b < x){
				printf("NO\n");
				break;
			}
			if (a == 0 || b == 0){
				printf("NO\n");
				break;
			}
			if (a > b){
				if (a >= x && (a - x) % b == 0){
					printf("YES\n");
					break;
				}
				a -= ((a - b - 1) / b + 1) * b;
			} else {
				if (b >= x && (b - x) % a == 0){
					printf("YES\n");
					break;
				}
				b -= ((b - a - 1) / a + 1) * a;
			}
		}
	}
	return 0;
}
