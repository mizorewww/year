/* Codeforces 548A - Mike and Fax
 * https://codeforces.com/problemset/problem/548/A
 * rating: 1100 | tags: brute force, implementation, strings
 * source: accepted submission #11290176 (GNU C) downloaded from Codeforces
 */

#include<stdio.h>
#include<string.h>
int main(){
char s[1000];
int n,i,j;
scanf("%s%d",&s,&n);
if(strlen(s)%n!=0){
printf("NO");
return 0;}
int pal=strlen(s)/n;
for(i=0;i<n;i++){
int coef=i*pal;
for(j=0;j<pal/2;j++){
if(s[coef]==s[(i+1)*pal-j-1]){
coef++;continue;}
else
{printf("NO");
return 0;}
}}
printf("YES");
return 0;
}
