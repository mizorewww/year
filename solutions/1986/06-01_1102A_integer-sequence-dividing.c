/* Codeforces 1102A - Integer Sequence Dividing
 * https://codeforces.com/problemset/problem/1102/A
 * rating: 800 | tags: math
 * source: accepted submission #48123079 (GNU C11) downloaded from Codeforces
 */

#include <stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    
    if(n%4 == 1 || n%4 == 2)
    printf("1");
    
    else
    printf("0");
    
}
