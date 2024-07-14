/* Codeforces 920F - SUM and REPLACE
 * https://codeforces.com/problemset/problem/920/F
 * rating: 2000 | tags: brute force, data structures, dsu, number theory
 * source: accepted submission #34940053 (GNU C11) downloaded from Codeforces
 */

#include <stdio.h>
#define N 1000000
#define inf 2e9
#define rep(i,x,y)  for(int i = x ; i< y ; i++)
#define F(i,x)  for(int i = 0 ; i< x ; i++)
#define ff first
#define ss second
#define pii pair < int , int>
#define ll long long
#define ull unsigned ll
#define MP make_pair
#define PB push_back
#define sca(a) scanf("%d",&a)
#define scaa(a,b) scanf("%d%d",&a,&b)
#define scaaa(a,b,c) scanf("%d%d%d",&a,&b,&c)


ll tree[4*N] ;
int a[N];
int flag[4*N];
int cnt[N];

int counter = 0;
void make(int node , int b ,int e){
   int m = (b+e) >> 1;
   int left = node << 1;
   int right = left +1;
   if( b== e){
     tree[node] = a[b];
     flag[node] = (a[b] > 2);
     return;
   }

   make(left,b,m);
   make(right,m+1,e);

   tree[node] = tree[left] + tree[right];
   flag[node] = flag[left] | flag[right];
}


ll query(int node , int b, int e , int l , int r){
 int m = (b+e) >> 1;
   int left = node << 1;
   int right = left +1;
   if(b > r || e < l) return 0;
   if( b >= l && e <= r) return tree[node];
   return query(left,b,m,l,r) + query(right,m+1,e,l,r);

}


void update(int node, int b ,int e , int l , int r){
 int m = (b+e) >> 1;
   int left = node << 1;
   int right = left +1;
   if(flag[node] == 0) return;
   if(b > r || e < l) return;

   if(b == e){
      tree[node] = cnt[tree[node]];
      flag[node] = (tree[node] > 2LL);
      return;
   }

   update(left,b,m,l,r);
   update(right,m+1,e,l,r);
   tree[node] = tree[left] + tree[right];
   flag[node] = flag[left] | flag[right];
   return;

}
int main()
{
//  freopen("in.txt" , "r" ,stdin);
  int n , m;
  scaa(n,m);
  for(int i = 1 ; i<= 1000000 ; i++){
    for(int j = i ; j<= 1000000 ; j += i){
      cnt[j]++;
    }
  }

 

  for(int i = 0 ; i< n ; i++){
    sca(a[i+1]);
  }

  make(1,1,n);
     while(m--){
      int x , l , r ;
        scaaa(x,l,r);
      if(x == 1){
            update(1,1,n,l,r);
      }
      else{
       ll res = query(1,1,n,l,r);
          printf("%I64d\n",res);
      }

     }
}
