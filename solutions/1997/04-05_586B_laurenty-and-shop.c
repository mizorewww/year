/* Codeforces 586B - Laurenty and Shop
 * https://codeforces.com/problemset/problem/586/B
 * rating: 1300 | tags: implementation
 * source: accepted submission #13560483 (GNU C) downloaded from Codeforces
 */

#include<stdio.h>
typedef unsigned u;
u L[111],R[111],M[111];
int main()
{
 u n,i,j,k,r=-1;
 scanf("%u",&n);
 for(i=0;++i<n;L[i]+=L[i-1])scanf("%u",L+i);
 for(i=-1;++i<n-1;)scanf("%u",R+i);
 for(i=n;i--;R[i]+=R[i+1]);
 for(i=-1;++i<n;)scanf("%u",M+i);
 for(i=-1;++i<n;)for(j=-1;++j<n;)if(i!=j)
 if(r>(k=L[i]+R[i]+M[i]+L[j]+R[j]+M[j]))r=k;
 printf("%u\n",r);
 return 0;
}
