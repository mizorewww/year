/* Codeforces 81A - Plug-in
 * https://codeforces.com/problemset/problem/81/A
 * rating: 1400 | tags: implementation
 * source: accepted submission #427821 (GNU C) downloaded from Codeforces
 */

#include<stdio.h>

char s[200000];
int st,i;


int main() {
	char c;
	while((c=getchar())!='\n' && c!=EOF) {
		if (st && s[st-1]==c) --st; else s[st++]=c;
	}
	for(i=0;i<st;i++) putchar(s[i]);
	puts("");
	return 0;
}
