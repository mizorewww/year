/* Codeforces 276D - Little Girl and Maximum XOR
 * https://codeforces.com/problemset/problem/276/D
 * rating: 1700 | tags: bitmasks, dp, greedy, implementation, math
 * source: accepted submission #3188207 (GNU C) downloaded from Codeforces
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<memory.h>
#include<assert.h>
#include<ctype.h>

#define ll long long
#define ull unsigned long long
#define max(a,b) (((a)>(b))?(a):(b))
#define min(a,b) (((a)<(b))?(a):(b))
#define abs(k) (((k)>0)?(k):(-(k)))
#define sqr(k) ((k)*(k))
#define mod(a,b) (((a)%(b)+(b))%(b))
#define mode(a,b) a=mod(a,b)
#define mset(a) memset(a,0,sizeof(a))
#define mcpy(a,b) memcpy(a,b,sizeof(a))
#define inf 1000000007
#define linf 1000000000000000000LL
#define pi 3.14159265358979323846

void fileio_in_out()
{
     freopen(".in","r",stdin);
     freopen(".out","w",stdout);
}

void fileio_txt()
{
     freopen("input.txt","r",stdin);
     freopen("output.txt","w",stdout);
}

//==================================================

#define N 2222222

ll n,m,ans,p;
int i,j,k,l,t;

int main()
{
    //fileio_in_out();
    //fileio_txt();
    
    scanf("%I64d%I64d",&n,&m);
    p=1;
    while(p<<1<=m)
      p<<=1;
    while(n>=p&&p>0)
      {
        m-=p;
        n-=p;
        p=1;
        while(p<<1<=m)
          p<<=1;
      }
    ans=(m!=n)?(p^(p-1)):0;
    printf("%I64d\n",ans);
    
    //system("pause");
    return 0;
}
