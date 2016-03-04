/* Codeforces 785A - Anton and Polyhedrons
 * https://codeforces.com/problemset/problem/785/A
 * rating: 800 | tags: implementation, strings
 * source: accepted submission #25512882 (GNU C) downloaded from Codeforces
 */

#include<stdio.h>


int main()
{   
	int n;
	char s[12];
	int count=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
	scanf("%s",s);
	if (*s=='T') count+=4;
if (*s=='C') count+=6;
if (*s=='O') count+=8;
if (*s=='D') count+=12;
if (*s=='I') count+=20;
}


printf("%d",count);
return 0;



}
