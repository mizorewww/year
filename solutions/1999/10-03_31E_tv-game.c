/* Codeforces 31E - TV Game
 * https://codeforces.com/problemset/problem/31/E
 * rating: 2400 | tags: dp
 * source: accepted submission #134975 (GNU C) downloaded from Codeforces
 */

#include <math.h>
#include <time.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define eps 1e-8
#define oo 9000000000000000000LL
#define pi 3.14159265359
#define zero(a) (abb(a)<=eps)
#define lowbit(a) ((a)&(-(a)))
#define abb(a) ((a)>0?(a):(-(a)))
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
#define cj(x1,y1,x2,y2) ((x1)*(y2)-(x2)*(y2))
#define dj(x1,y1,x2,y2) ((x1)*(y1)+(y1)*(y2))
#define dis(x1,y1,x2,y2) sqrt(((x2)-(x1))*((x2)-(x1))+((y2)-(y1))*((y2)-(y1)))

long long s[19]={0},f[40][19][19]={0};
long last[40][19][19]={0};
char str[40]={'\0'},ans[40]={'\0'};

int main()
{
   long i,j,k,l;
   scanf("%ld\n",&l);
   gets(str+1);
   s[1]=1;
   for (i=2;i<=l;i++)
      s[i]=s[i-1]*10;
   for (i=0;i<=2*l;i++)
      for (j=0;j<=l;j++)
         for (k=0;k<=l;k++)
            f[i][j][k]=-oo;
   f[2*l+1][0][0]=0;
   for (i=2*l;i>=1;i--)
      for (j=0;j<=l;j++)
         for (k=0;k<=l;k++)
         {
            if (j>0)
            {
               f[i][j][k]=f[i+1][j-1][k]+s[j]*(str[i]-'0');
               last[i][j][k]=0;
            }
            if (k>0&&f[i+1][j][k-1]+s[k]*(str[i]-'0')>f[i][j][k])
            {
               f[i][j][k]=f[i+1][j][k-1]+s[k]*(str[i]-'0');
               last[i][j][k]=1;
            }
         }
   j=k=l;
   for (i=1;i<=2*l;i++)
      if (last[i][j][k])
      {
         printf("H");
         k--;
      }
      else
      {
         printf("M");
         j--;
      }
   printf("\n");
   return 0;
}
