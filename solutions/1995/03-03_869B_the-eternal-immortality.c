/* Codeforces 869B - The Eternal Immortality
 * https://codeforces.com/problemset/problem/869/B
 * rating: 1100 | tags: math
 * source: accepted submission #31076139 (GNU C) downloaded from Codeforces
 */

#include <stdio.h>

int main(void) {
    long long int a,b;
    
    scanf("%lld %lld",&a,&b);
    
    long long int t=1,i;
    
    for(i=a+1;i<=b;i++)
    {
        t*=(i%10);
        t%=10;
        if(t==0)
        break;
    }
		printf("%lld\n",t);
		
    
	return 0;
}
