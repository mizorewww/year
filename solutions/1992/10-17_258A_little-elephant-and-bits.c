/* Codeforces 258A - Little Elephant and Bits
 * https://codeforces.com/problemset/problem/258/A
 * rating: 1100 | tags: greedy, math
 * source: accepted submission #18641953 (GNU C) downloaded from Codeforces
 */

#include<stdio.h>



char s[100500];



int main(){

	gets(s);

	int n=0;

	while(s[n]=='1')

		n++;

	if(!s[n])

		n--;

	s[n]=0;

	printf("%s%s",s,s+n+1);

}
