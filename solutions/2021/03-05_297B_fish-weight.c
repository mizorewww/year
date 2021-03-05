/* Codeforces 297B - Fish Weight
 * https://codeforces.com/problemset/problem/297/B
 * rating: 1600 | tags: constructive algorithms, greedy
 * source: accepted submission #3572340 (GNU C) downloaded from Codeforces
 */

//+++++++++++++++++++++++++++++//
//      Karan Aggarwal         //
//       IIIT-Hyderabad        //
//+++++++++++++++++++++++++++++//
// Topic: 
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<limits.h>
#include<math.h>
#define si(n) scanf("%d",&n)
#define rep(i,n) for(i=0;i<n;i++)
#define REP(i,a,b) for(i=a;i<b;i++)
#define pn printf("\n")
#define pw printf(" ")
#define pi(n) printf("%d",n)
#define pll(n) printf("%lld",n)
#define sll(n) scanf("%lld",&n)
#define ss(s) scanf("%s",s)
#define ps(s) printf("%s",s)
typedef long long LL;
//inline int readint(){int n=0;char c;while(1){ c=getchar_unlocked();if(c=='\n'||c==' '||c==EOF)break;n=(n<<3) + (n<<1) +c-'0';}return n;}
//inline long long readlonglong(){long long n=0;char c;while(1){ c=getchar_unlocked();if(c=='\n'||c==' '||c==EOF)break;n=(n<<3) + (n<<1) +c-'0';}return n;}
int abs(int a){ if(a<0)return -1*a; return a;}
int big(int a,int b){if(a>b)return a;return b;}
int small(int a,int b){if(a<b)return a;return b;}
int compare(const void *a, const void *b)
{
    int *p1=(int*)a;
    int *p2=(int*)b;
    return *p2-*p1;
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
int a[100000];
int b[100000];
int c[100000];
int d[100000];
int main()
{
    int sd=0,sc=0,m,l,ans,sum,min,max,n,i,j,k,x,y,t;
    si(n);
    si(m);
    si(k);
    rep(i,n)si(a[i]);
    rep(i,m)si(b[i]);
    if(n>m)
    {
        printf("YES");
        return 0;
    }
    qsort(a,n,sizeof(int),compare);
    qsort(b,m,sizeof(int),compare);
    i=j=0;
    sc=sd=0;
    while(1)
    {
        if(i==n)break;
        if(j==m)break;
        if(a[i]>b[j])
            c[sc++]=a[i++];
        else if(a[i]<b[j])
            d[sd++]=b[j++];
        else if(a[i]==b[j]){i++;j++;}
    }
    while(i<n)
            c[sc++]=a[i++];
    while(j<m)
            d[sd++]=b[j++];
    n=sc;m=sd;
    i=j=0;
    while(i<n && j<m)
    {
        if(c[i]>d[j])
            break;
        i++;j++;
    }
    if(i<n && j<m)
        printf("YES");
    else
        printf("NO");
    return 0;
}
