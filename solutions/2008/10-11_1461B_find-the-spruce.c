/* Codeforces 1461B - Find the Spruce
 * https://codeforces.com/problemset/problem/1461/B
 * rating: 1400 | tags: brute force, dp, implementation
 * source: accepted submission #100929771 (GNU C11) downloaded from Codeforces
 */

#include<stdio.h>
int main(){int t,sum,i,n,k,j,m,l,a1[505][505],a2[505][505],a[505][505],c;
char s[505][505];
 scanf("%d",&t);
 for(i=0;i<t;i++)
 {
  scanf("%d%d",&n,&m);
  for(j=0;j<n;j++)
  {
   scanf(" %s",s[j]);
  }
  for(j=0;j<n;j++)
  {
   for(k=0;k<m;k++)
   {
    a1[j][k]=0;
    a2[j][k]=0;
    a[j][k]=0;
   }
  }
  for(j=0;j<n;j++)
  {c=1;
   for(k=0;k<m;k++)
   {
    if(s[j][k]=='*')
    {
     a1[j][k]=c;
     c++;
    }
    else
    c=1;
   }
   c=1;
   for(k=m-1;k>=0;k--)
   {
    if(s[j][k]=='*')
    {
     a2[j][k]=c;
     c++;
    }
    else
    c=1;
   }
   for(k=0;k<m;k++)
   {
    if(a1[j][k]>a2[j][k])
    a[j][k]=a2[j][k];
    else
    a[j][k]=a1[j][k];
   }
  }
  sum=0;
  for(j=0;j<n;j++)
  {
   for(k=0;k<m;k++)
   {if(s[j][k]=='*'){
    for(l=j;l<n;l++)
    {
     if((a[l][k])<=(l-j))
     break;
    }
    sum=sum+l-j;}
   }
  }
  printf("%d\n",sum);
 }
 return 0;
}
