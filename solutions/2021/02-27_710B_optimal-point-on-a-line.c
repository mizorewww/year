/* Codeforces 710B - Optimal Point on a Line
 * https://codeforces.com/problemset/problem/710/B
 * rating: 1400 | tags: brute force, sortings
 * source: accepted submission #20066894 (GNU C) downloaded from Codeforces
 */

#include<stdio.h>

int mod(int a)

{

    if(a<0)

        return -a;

    return a;

}

void marge(int *p,int n)

{

    int i,j=0,k=n/2,a[n];

    if(n==1)

        return;

    marge(p,n/2);

    marge(p+n/2,n-n/2);

    for(i=0;i<n;i++)

    {

        if((*(p+j))<(*(p+k))&&j<(n/2))

        {

            a[i]=*(p+j);

            j++;

        }

        else if((*(p+j))>=(*(p+k))&&k<n)

        {

            a[i]=*(p+k);

            k++;

        }

        else if(j==(n/2))

        {

            a[i]=*(p+k);

            k++;

        }

        else

        {

            a[i]=*(p+j);

            j++;

        }

    }

    for(i=0;i<n;i++)

        *(p+i)=a[i];

}

int main()

{

    int n,a[300000],i;

    scanf("%d",&n);

    for(i=0;i<n;i++)

        scanf("%d",&a[i]);

    marge(a,n);

    printf("%d",a[(n-1)/2]);

}
