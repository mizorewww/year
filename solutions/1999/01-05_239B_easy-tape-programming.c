/* Codeforces 239B - Easy Tape Programming
 * https://codeforces.com/problemset/problem/239/B
 * rating: 1500 | tags: brute force, implementation
 * source: accepted submission #2502984 (GNU C) downloaded from Codeforces
 */

#include <stdio.h>
#include <string.h>

char st[105],tmp[105];

int main()
{
    char dp;
    int num[10],i,l,n,q,r,cp,tp,len,ncp;

    scanf("%d%d%s",&n,&q,st);
    while (q--) {
        scanf("%d%d",&l,&r);
        for (i=l; i<=r; ++i)
            tmp[i-l]=st[i-1];
        tmp[r-l+1]='\0';
        len=r-l+1;
        memset(num,0,sizeof(num));
        cp=0;
        dp='>';
        while (cp>=0 && cp<len)
            if (tmp[cp]>='0' && tmp[cp]<='9') {
                ++num[tmp[cp]-'0'];
                if (tmp[cp]=='0') {
                    tp=(dp=='<')?-1:0;
                    for (i=cp+1; i<=len; ++i)
                        tmp[i-1]=tmp[i];
                    cp+=tp;
                    --len;
                } else {
                    --tmp[cp];
                    cp+=((dp=='<')?-1:1);
                }
            } else {
                dp=tmp[cp];
                ncp=cp+((dp=='<')?-1:1);
                if (ncp>=0 && ncp<len && (tmp[ncp]=='<' || tmp[ncp]=='>')) {
                    tp=(dp=='<')?-1:0;
                    for (i=cp+1; i<=len; ++i)
                        tmp[i-1]=tmp[i];
                    cp+=tp;
                    --len;
                } else
                    cp=ncp;
            }
        for (i=0; i<9; ++i)
            printf("%d ",num[i]);
        printf("%d\n",num[9]);
    }
    return 0;
}
