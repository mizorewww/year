/* Codeforces 1607A - Linear Keyboard
 * https://codeforces.com/problemset/problem/1607/A
 * rating: 800 | tags: implementation, strings
 * source: accepted submission #134072827 (GNU C11) downloaded from Codeforces
 */

#include <stdio.h>

char input[51];
int num[26];

int abs(int a) {
	if (a < 0)return -a;
	return a;
}

int main() {
	int t;
	scanf("%d", &t);

	while (t--) {
		char temp[27];
		scanf("%s", temp);
		for (int i = 0; i < 26; i++) {
			num[temp[i] - 'a'] = i;
		}

		scanf("%s", input);

		char* ptr = &input[1];
		int ans = 0;
		while (*ptr) {
			ans += abs(num[(*ptr)-'a'] - num[(*(ptr-1)) - 'a']);
			ptr += 1;
		}

		printf("%d\n", ans);
	}
}
