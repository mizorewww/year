/* Codeforces 1553C - Penalty
 * https://codeforces.com/problemset/problem/1553/C
 * rating: 1200 | tags: bitmasks, brute force, dp, greedy
 * source: accepted submission #123349308 (GNU C11) downloaded from Codeforces
 */

#include <stdio.h>

int solve(char s[])
{
	int answer;
	int A=0,B=0,A_q=0,B_q=0;
	int number;
	int i;
	for(i = 0;i<=9;i++)
	{
		if((i+1)%2)
		{
			if(s[i] == '1') A++;
			else if(s[i] == '?') A_q++;
		}
		else
		{
			if(s[i] == '1') B++;
			else if(s[i] == '?') B_q++;
		}
		if(A + A_q + (9-i)/2 < B || A +A_q>B+(10-i)/2) break; 
		if(B + B_q + (10-i)/2 < A|| B+ B_q>A+(9-i)/2) break; 
	}
	if(i == 10) return 10;
	return i+1;
}

int main(int argc, char const *argv[])
{
	int t;
	int i;
	char s[20];
	int answer;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%s", &s);
		answer = solve(s);
		printf("%d\n", answer);
	}
	return 0;
}
