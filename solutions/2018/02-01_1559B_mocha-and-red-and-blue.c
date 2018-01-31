/* Codeforces 1559B - Mocha and Red and Blue
 * https://codeforces.com/problemset/problem/1559/B
 * rating: 900 | tags: dp, greedy
 * source: accepted submission #125955638 (GNU C11) downloaded from Codeforces
 */

#include <stdio.h>

char s[107];

int main(){
	int t;
	scanf("%d", &t);
	for (int i = 1; i <= t; i++){
		int n, j = 1;
		scanf("%d", &n);
		scanf("%s", &s[1]);
		s[n + 1] = 'B';
		while (j <= n && s[j] == '?') j++;
		for (int k = j - 1; k >= 1; k--){
			s[k] = s[k + 1] == 'B' ? 'R' : 'B';
		}
		for (; j <= n; j++){
			if (s[j] == '?') s[j] = s[j - 1] == 'B' ? 'R' : 'B';
		}
		for (int k = 1; k <= n; k++){
			printf("%c", s[k]);
		}
		printf("\n");
	}
	return 0;
}
