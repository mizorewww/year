/* Codeforces 675C - Money Transfers
 * https://codeforces.com/problemset/problem/675/C
 * rating: 2100 | tags: constructive algorithms, data structures, greedy, sortings
 * source: accepted submission #17949786 (GNU C) downloaded from Codeforces
 */

//
//  main.c
//  160517 CF-C
//
//  Created by tjua on 5/17/16.
//  Copyright © 2016 tjua. All rights reserved.
//

#include <stdio.h>
#define U 1000009
#define N 100001

#define abs(x) ((x)>0?(x):-(x))

const int u = U;
int poi[U];

int n,m=1;
long long num[N]; //[0] abandent
int cou[N];
int nex[N];

void add(long long s);
int max=1;

void add(long long s){
    int p,pp = abs(s%u);  //-s
    for (p = poi[pp]; p != 0 && num[p] != s; p = nex[p])
        ;
    if (p==0){
        num[m]=s;
        cou[m]=1;
        nex[m]=poi[pp];
        poi[pp]=m++;
    }
    else {
        cou[p]++;
        if (max<cou[p]) max=cou[p];
    }
    return;
}


int main(int argc, const char * argv[]) {
    int i,a;
    long long s = 0;
    
    scanf("%d",&n);
    for (i=0;i<n;i++) {
        scanf("%d",&a);
        s+=a;
        add(s);
    }
    
    printf("%d\n",n-max);
    
    //printf("Hello, World!\n");
    return 0;
}
