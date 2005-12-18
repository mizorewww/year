/* Codeforces 817C - Really Big Numbers
 * https://codeforces.com/problemset/problem/817/C
 * rating: 1600 | tags: binary search, brute force, dp, math
 * source: accepted submission #27806266 (GNU C11) downloaded from Codeforces
 */

#include <stdio.h>
#include <stdlib.h>
long long dig(long long k)
{
    long long sum = 0;
    while(k)
    {
        sum += k%10;
        k /= 10;
    }
    return sum;
}
int main()
{
    long long n,s,i,sum = 0,b;
    scanf("%I64d %I64d",&n,&s);
    b = s+200 < n ? s+200 : n;
    for(i=s;i<=b;i++)
    {
        if(i-dig(i) >= s)
            sum ++;
    }
    sum += n - b;
    printf("%I64d\n",sum);
    return 0;
}
