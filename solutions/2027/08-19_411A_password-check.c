/* Codeforces 411A - Password Check
 * https://codeforces.com/problemset/problem/411/A
 * rating: 800 | tags: *special, implementation
 * source: accepted submission #6369153 (GNU C) downloaded from Codeforces
 */

#include <stdio.h>
int main(void) {
	char s[101];
	unsigned short i, c[3] = {0}, tmp;
	scanf("%s", s);
	for(i = 0; s[i]; ++i) {
		tmp = s[i];
		if((tmp >= 48) && (tmp <= 57)) c[0] = 1;
		if((tmp >= 65) && (tmp <= 90)) c[1] = 1;
		if((tmp >= 97) && (tmp <= 122)) c[2] = 1;
	}
	if((c[0] * c[1] * c[2]) && (i >= 5)) printf("Correct");
	else printf("Too weak");
	return 0;
}
