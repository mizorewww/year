/* Codeforces 877A - Alex and broken contest
 * https://codeforces.com/problemset/problem/877/A
 * rating: 1100 | tags: implementation, strings
 * source: accepted submission #31640553 (GNU C11) downloaded from Codeforces
 */

#include <stdio.h>
#include <string.h>

int main() {
	char str[101];
	int status = 0;
	int count = 0;
	char* names[] = {"Danil", "Olya", "Slava", "Ann", "Nikita"};
	const int names_num = 5;

	if (fgets(str, 100, stdin) != NULL) {
		for (int i = 0; i < names_num; i++) {
			char* test = str;
			while (test = strstr(test, names[i])) {
				//printf("DDD %s\n", names[i]);
				count++;
				test += strlen(names[i]);
			}
		}
	}

	if (count == 1) {
		printf("YES\n");
	} else {
		printf("NO\n");
	}
	
}
