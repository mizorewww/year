/* Codeforces 679B - Bear and Tower of Cubes
 * https://codeforces.com/problemset/problem/679/B
 * rating: 2200 | tags: binary search, dp, greedy
 * source: accepted submission #22076608 (GNU C) downloaded from Codeforces
 */

#include<stdio.h>
typedef long long ll;
ll cube(ll x)
{return (x*x*x);}

void func(ll vol,ll steps,ll cur,ll *blocks,ll *maxvol)
{

	if (vol==0)
	{
		if (steps>*blocks)
		{
			*blocks=steps;
			*maxvol=cur;
		}
		if (steps==*blocks && cur>*maxvol)
			*maxvol=cur;
		return;
	}
	ll x=1;
	while(cube(x+1)<=vol)
		x++;
	ll temp=cube(x);
	func(vol-temp,steps+1,cur+temp,blocks,maxvol);
	if (x>=1)
	{ll temp2=cube(x-1);
	func(temp-temp2-1,steps+1,cur+temp2,blocks,maxvol);
	}
	return;
}



int main()
{
	ll m;
	scanf("%lld",&m);
	ll a=0,b=0;
	func(m,0,0,&a,&b);
	printf("%lld %lld\n",a,b);
	return 0;

}
