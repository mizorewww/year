/* Codeforces 949A - Zebras
 * https://codeforces.com/problemset/problem/949/A
 * rating: 1600 | tags: greedy
 * source: accepted submission #36388162 (GNU C) downloaded from Codeforces
 */

#include<stdio.h>
#include<string.h>

int c,m;
char buf[200020];
int nxt[200020];
int hd[200020];
int tl[200020];
int l[200020];

int main()
{
 int i;
 for(i=0;i<=200010;i++)
 {
  nxt[i]=200012;
  hd[i]=200012;
  tl[i]=200012;
  l[i]=0;
 }
 m=0;c=0;
 scanf("%s",buf);
 for(i=0;buf[i];i++)
 {
  if(buf[i]==48)
  {
   c++;
   if(c>m)
   {
    m=c;
    hd[c]=i;
   }
   l[c]++;
   nxt[tl[c]]=i;
   tl[c]=i;
  }
  if(buf[i]==49)
  {
   l[c]++;
   nxt[tl[c]]=i;
   tl[c]=i;
   c--;
   if(c<0)
   {
    printf("-1\n");
    return 0;
   }
  }
 }
 if(c!=m)
 {
  printf("-1\n");
  return 0;
 }
 printf("%d\n",m);
 for(c=1;c<=m;c++)
 {
  printf("%d",l[c]);
  for(i=hd[c];i!=200012;i=nxt[i])
   printf(" %d",i+1);
  printf("\n");
 }
 return 0;
}
