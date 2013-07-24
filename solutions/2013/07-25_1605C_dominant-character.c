/* Codeforces 1605C - Dominant Character
 * https://codeforces.com/problemset/problem/1605/C
 * rating: 1400 | tags: brute force, greedy, implementation, strings
 * source: accepted submission #135137816 (GNU C11) downloaded from Codeforces
 */

#include <stdio.h>

char s[1000007];

int main(){
	int t;
	scanf("%d", &t);
	for (int i = 1; i <= t; i++){
		int n, ans = -1;
		scanf("%d", &n);
		scanf("%s", &s[1]);
		for (int j = 1; j < n; j++){
			if (s[j] == 'a' && s[j + 1] == 'a'){
				ans = 2;
				break;
			}
		}
		if (ans == -1){
			for (int j = 1; j <= n - 2; j++){
				if (s[j] == 'a' && (s[j + 1] == 'b' || s[j + 1] == 'c') && s[j + 2] == 'a'){
					ans = 3;
					break;
				}
			}
			if (ans == -1){
				for (int j = 1; j <= n - 3; j++){
					if (s[j] == 'a' && ((s[j + 1] == 'b' && s[j + 2] == 'c') || (s[j + 1] == 'c' && s[j + 2] == 'b')) && s[j + 3] == 'a'){
						ans = 4;
						break;
					}
				}
				if (ans == -1){
					for (int j = 1; j <= n - 6; j++){
						if (s[j] == 'a' && s[j + 3] == 'a' && s[j + 6] == 'a' && ((s[j + 1] == 'b' && s[j + 2] == 'b' && s[j + 4] == 'c' && s[j + 5] == 'c') || (s[j + 1] == 'c' && s[j + 2] == 'c' && s[j + 4] == 'b' && s[j + 5] == 'b'))){
							ans = 7;
							break;
						}
					}
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
