/* Codeforces 254A - Cards with Numbers
 * https://codeforces.com/problemset/problem/254/A
 * rating: 1200 | tags: constructive algorithms, sortings
 * source: accepted submission #2735431 (GNU C) downloaded from Codeforces
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int index,num;
} Card;
Card C[600001];
int Hash[5001];

int cmp(const void *a,const void *b)
{
    return (*(Card *)a).num-(*(Card *)b).num;
}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int N,i,j,Flag,Min,Max;
    scanf("%d",&N);
    for(i=1; i<=N+N; ++i)
    {
        scanf("%d",&C[i].num);
        C[i].index=i;
        ++Hash[C[i].num];
    }
    qsort(C+1,N+N,sizeof(Card),cmp);
    for(Flag=i=1; i<5001; ++i)
    {
        if(Hash[i]%2!=0)
        {
            Flag=0;
            break;
        }
    }
    if(!Flag)
    {
        printf("-1\n");
    }
    else
    {
        for(i=1;i<=N+N;i+=2)
        {
            printf("%d %d\n",C[i].index,C[i+1].index);
        }
    }
    return 0;
}
