/* Codeforces 471C - MUH and House of Cards
 * https://codeforces.com/problemset/problem/471/C
 * rating: 1700 | tags: binary search, brute force, greedy, math
 * source: accepted submission #7971886 (GNU C) downloaded from Codeforces
 */

#include<stdio.h>
int main()
{
  long long int n,i,t[3]={0},j,s;
   scanf("%I64d",&n);
   for(i=5,s=2,j=0;s<=n;i+=3)
	{
         t[s%3]++;
         s+=i;
        }
    printf("%I64d\n",t[n%3]);
   
return 0;
}
