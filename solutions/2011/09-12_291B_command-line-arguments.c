/* Codeforces 291B - Command Line Arguments
 * https://codeforces.com/problemset/problem/291/B
 * rating: 1300 | tags: *special, implementation, strings
 * source: accepted submission #3530827 (GNU C) downloaded from Codeforces
 */

#include<stdio.h>
char g(char *c){ char t=getchar();if(t=='\n')t=0;return *c=t;}
int main(){
	char c;
	while(g(&c)){
		while(c==' ')g(&c);
		if(!c)break;
		putchar('<');
		if(c=='"'){
			while(g(&c)!='"')putchar(c);
		}else do{
			if(!c){printf(">\n");return 0;}
			putchar(c);
		}while(g(&c)!=' ');
		printf(">\n");
	}
	return 0;
}
