/* Codeforces 1504A -  Déjà Vu
 * https://codeforces.com/problemset/problem/1504/A
 * rating: 800 | tags: constructive algorithms, strings
 * source: accepted submission #111911546 (GNU C11) downloaded from Codeforces
 */

#include <stdio.h>
#include <string.h>

int main() {
	int t;
	char s[300002];
	int isPos;
	int isFind;
	int i, j;
	scanf("%d", &t);
	while (t--) {
		isPos = 0;
		j = 0;
		scanf("%s", s);
		for (i=0;i<strlen(s);i++) {
			if (s[i]!='a') {
				isPos = 1;
				j = strlen(s) - i;
				break;
			}
		}
		if (isPos==1) {
			for (i=strlen(s);i>=j;i--) {
				s[i+1] = s[i];
			}
			s[j] = 'a';
			printf("Yes\n");
			printf("%s\n", s);
		}
		else printf("No\n");
	}
}
