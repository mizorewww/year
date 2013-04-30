/* Codeforces 1214C - Bad Sequence
 * https://codeforces.com/problemset/problem/1214/C
 * rating: 1200 | tags: data structures, greedy
 * source: accepted submission #59999222 (GNU C11) downloaded from Codeforces
 */

#include<stdio.h>
int main(){
int n,i,a=0,b=0;
scanf("%d",&n);
char x,s[n+1];
scanf("%c",&x);
gets(s);
for(i=0;i<n;i++){
    if(s[i]=='(') a++;
    else b++;
    if(b-a>1) break;
}
if(i==n){
    if(a==b) {printf("YES");
    return 0;}
}
printf("NO");
return 0;

}
