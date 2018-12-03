/* Codeforces 1184A1 - Heidi Learns Hashing (Easy)
 * https://codeforces.com/problemset/problem/1184/A1
 * rating: 1200 | tags: brute force, math, number theory
 * source: accepted submission #56648417 (GNU C11) downloaded from Codeforces
 */

#include<stdio.h>
int main()
{
    long long r;
    scanf("%lld",&r);
    if(r<5 || r%2==0) printf("NO");
    else
    {
        printf("%I64d %I64d",1LL,(r-3)/2);
    }
}
