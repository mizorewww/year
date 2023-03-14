/* Codeforces 474F - Ant colony
 * https://codeforces.com/problemset/problem/474/F
 * rating: 2100 | tags: data structures, math, number theory
 * source: accepted submission #8120908 (GNU C) downloaded from Codeforces
 */

#include <stdio.h>
long long ab[100005];
struct p{
    long long g,r,rc;
}   a[400000];
long long gcd (long long a,long long b )
{
  long long c;
  while ( a != 0 ) {
     c = a; a = b%a;  b = c;
  }
  return b;
}

    
int main() {
    long long n,m,p,q,t,g,i,j,k,b,c,rc,r;
    scanf("%lld",&n);
    i=131071;
    for(i=1;i<=n;++i){
        scanf("%lld",&ab[i]);
        a[131071+i].g=ab[i];
        a[131071+i].r=ab[i];
        a[131071+i].rc=1;
    }
    for(i=n+1;i<=131072;++i){
        a[131071+i].g=0;;
        a[131071+i].r=10000000000000;
        a[131071+i].rc=0;
    }
    for(i=131071;i>0;--i){
        a[i].g=gcd(a[2*i].g,a[2*i+1].g);
        if(a[2*i].r==a[2*i+1].r){       a[i].r=a[2*i].r;a[i].rc=a[2*i].rc+a[2*i+1].rc;}
        else if(a[2*i].r<a[2*i+1].r)    {       a[i].r=a[2*i].r;a[i].rc=a[2*i].rc;}
        else        {       a[i].r=a[2*i+1].r;a[i].rc=a[2*i+1].rc;}
    }
    scanf("%lld",&t);
    while(t--){
        scanf("%lld %lld",&j,&k);
        p=131071+j;q=131071+k;
        g=0;
        
        rc=0;
        r=1000000000000000;
        while(p>0&&q>0&&p<=q){
            if(p==q){
                    g=gcd(g,a[p].g);
                if(r>a[p].r){   r=a[p].r,rc=a[p].rc;}
                else if(r==a[p].r){ rc+=a[p].rc;}
                break;
            }
            if(p%2!=0){
            if(q%2==0){ 
                g=gcd(g,gcd(a[p].g,a[q].g));
                if(r>a[p].r){   r=a[p].r,rc=a[p].rc;}
                else if(r==a[p].r){ rc+=a[p].rc;}
                if(r>a[q].r){   r=a[q].r,rc=a[q].rc;}
                else if(r==a[q].r){ rc+=a[q].rc;}
                p=p/2 +1;q=q/2 -1;
            }else{
                g=gcd(g,a[p].g);
                if(r>a[p].r){   r=a[p].r,rc=a[p].rc;}
                else if(r==a[p].r){ rc+=a[p].rc;}
                p=p/2+1; q=q/2;
            }
            
        }else{
            if(q%2==0){
                g=gcd(g,a[q].g);
                if(r>a[q].r){   r=a[q].r,rc=a[q].rc;}
                else if(r==a[q].r){ rc+=a[q].rc;}
                p=p/2; q=q/2 -1;
            }else{
                p=p/2;q=q/2;
            }
        }
            
        }
        if(r==g)    printf("%lld\n",k-j+1-rc);
        else printf("%lld\n",k-j+1);
    }
        
    
    return 0;
}
