/* Codeforces 409H - A + B Strikes Back
 * https://codeforces.com/problemset/problem/409/H
 * rating: 1500 | tags: *special, brute force, constructive algorithms, dsu, implementation
 * source: accepted submission #6225213 (GNU C) downloaded from Codeforces
 */

#include<stdio.h>
int main(){
    int a,b;

    scanf("%d %d", &a, &b);
    if(a>=0&&a<=1000&&b>=0&&b<=1000)
        printf("%d\n", a+b);
    
    return 0;
}
