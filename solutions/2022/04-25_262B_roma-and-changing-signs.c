/* Codeforces 262B - Roma and Changing Signs
 * https://codeforces.com/problemset/problem/262/B
 * rating: 1200 | tags: greedy
 * source: accepted submission #2919324 (GNU C) downloaded from Codeforces
 */

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,b) REP(i,0,b)
#define si(n) scanf("%d",&n)
#define pi(n) printf("%d",n)
#define abs(a) a>=0?(a):(-a)
int main()
{
    int n,x,y,i,j,c,sum=0,k,min=1000000;
    si(n);
    si(k);
    rep(i,n)
    {
	si(x);
	if(x<0 && k)
	{
	    x*=-1;
	    k--;
	}

	if(x<min)
	    min=x;
	sum+=x;
    }
    if(k && k&1)sum-=2*min;
    pi(sum);
    return 0;
}
