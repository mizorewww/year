/* Codeforces 1132C - Painting the Fence
 * https://codeforces.com/problemset/problem/1132/C
 * rating: 1700 | tags: brute force
 * source: accepted submission #50846662 (GNU C11) downloaded from Codeforces
 */

#include<stdio.h>
#include<string.h>
#define MAX 300001

int temp[MAX];
void mergesort(int Array[],int first,int last)
{
    if(first==last) return;
    int middle=(first+last)/2;
    mergesort(Array,first,middle);
    mergesort(Array,middle+1,last);
    int i,j,k;
    for(i=first,j=first,k=middle+1;i<=last;i++)
    {
        if(j==middle+1) temp[i]=Array[k++];
        else if(k==last+1) temp[i]=Array[j++];
        else if(Array[k]>Array[j]) temp[i]=Array[k++];
        else temp[i]=Array[j++];
    }
    for(i=first;i<=last;i++)
    {
        Array[i]=temp[i];
    }
}
int main()
{
    int q,n,i,j,maximum=0,counter=0;
    scanf("%d %d",&n,&q);
    int l[q],r[q],cells[n],ones[n],twos[n];
    for(i=0;i<q;i++)
    {
        scanf("%d %d",&l[i],&r[i]);
        l[i]--;
        r[i]--;

    }
    for(i=0;i<n;i++)
    {
        cells[i]=0;
        ones[i]=0;
        twos[i]=0;
    }
    for(i=0;i<q;i++)
    {
        for(j=l[i];j<=r[i];j++)
        {
            if(cells[j]==0) counter++;
            cells[j]++;
        }
    }
    //printf("counter=%d\n",counter);
    for(i=0;i<n;i++)
    {
        if(cells[i]==1) ones[i]=1;
        if(cells[i]==2) twos[i]=1;
    }
    for(i=1;i<n;i++)
    {
        ones[i]=ones[i-1]+ones[i];
        twos[i]=twos[i-1]+twos[i];
    }
    for(i=0;i<q;i++)
    {
        for(j=i+1;j<q;j++)
        {
            int coloured=counter;
            if(l[i]>0)
            {
                coloured=coloured-ones[r[i]]+ones[l[i]-1];
            }
            else
            {
                coloured=coloured-ones[r[i]];
            }
            if(l[j]>0)
            {
                coloured=coloured-ones[r[j]]+ones[l[j]-1];
            }
            else
            {
                coloured=coloured-ones[r[j]];
            }
            if(l[j]>=l[i]&&l[j]<=r[i])
            {
                int beg=l[j];
                int finish;
                if(r[j]<r[i]) finish=r[j];
                else finish=r[i];
                if(beg>0)
                {
                    coloured=coloured-twos[finish]+twos[beg-1];
                }
                else
                {
                    coloured=coloured-twos[finish];
                }
            }
            else if(l[i]>=l[j]&&l[i]<=r[j])
            {
                int beg=l[i];
                int finish;
                if(r[i]<r[j]) finish=r[i];
                else finish=r[j];
                if(beg>0)
                {
                    coloured=coloured-twos[finish]+twos[beg-1];
                }
                else
                {
                    coloured=coloured-twos[finish];
                }
            }
            if(coloured>maximum) maximum=coloured;
        }
    }
    printf("%d",maximum);
    return 0;
}
