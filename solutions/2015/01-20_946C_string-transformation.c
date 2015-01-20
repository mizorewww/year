/* Codeforces 946C - String Transformation
 * https://codeforces.com/problemset/problem/946/C
 * rating: 1300 | tags: greedy, strings
 * source: accepted submission #36637830 (GNU C) downloaded from Codeforces
 */

#include <stdio.h>
#include <string.h>
char s[100005];
int main()
{
 scanf("%s",s);
 char ch='a';
 int p=strlen(s);
 for (int i=0;i<p && ch<='z';i++) if (s[i]<=ch) s[i]=ch++;
 if (ch<='z') printf("-1\n");
 else printf("%s\n",s);
 return 0;
}
