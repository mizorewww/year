/* Codeforces 436A - Feed with Candy
 * https://codeforces.com/problemset/problem/436/A
 * rating: 1500 | tags: greedy
 * source: accepted submission #6881814 (GNU C) downloaded from Codeforces
 */

#include <stdio.h>
#include <stdlib.h>

int t[2005];
int h[2005];
int m[2005];
int used[2005];
	

int main(void) {
	int n, x;

	int i, j, k;
	int total[2];
	int eat;
	int jump;
	int max;
	int idx;

	scanf(" %d %d", &n, &x);

	for (i = 0; i < n; i++) {
		scanf(" %d %d %d", &t[i], &h[i], &m[i]);
	}

	for (k = 0; k < 2; k++) {
		total[k] = 0;
		eat = k;
		jump = x;

		for (i = 0; i < n; i++) {
			used[i] = 0;
		}

		for (i = 0; i < n; i++) {
			max = -1;
			for (j = 0; j < n; j++) {
				if (jump >= h[j] && used[j] == 0 && t[j] == eat && m[j] > max) {
					max = m[j];
					idx = j;
				}
			}
			if (max != -1) {
				total[k]++;
				jump += m[idx];
				used[idx] = 1;
				eat = 1 - eat;
			} else {
				break;
			}
		}
	}

	if (total[0] > total[1]) {
		printf("%d\n", total[0]);
	} else {
		printf("%d\n", total[1]);
	}

	return 0;
}
