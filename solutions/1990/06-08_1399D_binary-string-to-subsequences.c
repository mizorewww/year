/* Codeforces 1399D - Binary String To Subsequences
 * https://codeforces.com/problemset/problem/1399/D
 * rating: 1500 | tags: constructive algorithms, data structures, greedy, implementation
 * source: accepted submission #89050871 (GNU C11) downloaded from Codeforces
 */

#include <stdio.h>
#include <stdlib.h>
typedef struct node no;
struct node
{
    int val;
    no* next;
};
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d\n",&n);
        char arr[n+1];
        int c[2]={0,0},i,stc[n],k,ct=0;
        no **ro,*x;
        ro=(no**)malloc(2*sizeof(no*));
        ro[0]=(no*)malloc(sizeof(no));
        ro[1]=(no*)malloc(sizeof(no));
        for(i=0;i<n;i++)
        {
            scanf("%c",&arr[i]);
            k=arr[i]-48;
            if(c[1-k]==0)
            {
                ct++;
                x=(no*)malloc(sizeof(no));
                x->val=ct;
                stc[i]=ct;
                if(c[k]>0)
                x->next=ro[k]->next;
                ro[k]->next=x;
                c[k]++;
            }
            else
            {
                x=(no*)malloc(sizeof(no));
                x->val=(ro[1-k]->next)->val;
                stc[i]=x->val;
                x->next=ro[k]->next;
                ro[k]->next=x;
                x=(ro[1-k]->next);
                ro[1-k]->next=x->next;
                c[k]++;
                c[1-k]--;
                free(x);
            }
        }
        printf("%d\n",ct);
        for(i=0;i<n;i++) printf("%d ",stc[i]);
        printf("\n");
    }
    return 0;
}
