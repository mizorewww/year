/* Codeforces 169B - Replacing Digits
 * https://codeforces.com/problemset/problem/169/B
 * rating: 1100 | tags: greedy
 * source: accepted submission #1410971 (GNU C) downloaded from Codeforces
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char s1[100005], s2[100005];
int cmp(const void *a, const void *b)
{
	return *(char *)b - *(char *)a;
}
int main()
{
	int len1, len2, i, j;
	while (scanf("%s %s", s1, s2) != EOF)
	{
		len1 = strlen(s1);
		len2 = strlen(s2);
		qsort(s2, len2, sizeof(char), cmp);
		for (i=0,j=0; i<len1&&j<len2;)
		{
			if (s1[i]<s2[j])
			{
				s1[i] = s2[j];
				i++, j++;
			}
			else
				i++;
		}
		puts(s1);
	}
	
	return 0;
}
