/* Codeforces 1374E1 - Reading Books (easy version)
 * https://codeforces.com/problemset/problem/1374/E1
 * rating: 1600 | tags: data structures, greedy, sortings
 * source: accepted submission #85377257 (GNU C11) downloaded from Codeforces
 */

#include <stdio.h>
#include <stdlib.h>

void merge(long long int arr[], long long int l, long long int m, long long int r)
{
    long long int i, j, k;
    long long int n1 = m - l + 1;
    long long int n2 =  r - m;

    /* create temp arrays */
    long long int L[n1], R[n2];

    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];

    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    /* Copy the remaining elements of L[], if there
       are any */
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    /* Copy the remaining elements of R[], if there
       are any */
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

/* l is for left index and r is right index of the
   sub-array of arr to be sorted */
void mergeSort(long long int arr[], long long int l, long long int r)
{
    if (l < r)
    {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        long long int m = l+(r-l)/2;

        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);

        merge(arr, l, m, r);
    }
}

int main()
{
	long long int n, k;
	scanf("%lld %lld", &n, &k);
	
	long long int *alfa = (long long int*)malloc(200000*sizeof(long long int));
    long long int *beta = (long long int*)malloc(200000*sizeof(long long int));
    long long int *gamma = (long long int*)malloc(200000*sizeof(long long int));
    
    long long int ca = 0;
    long long int cb = 0;
    long long int cg = 0;
    long long int i;
    for ( i = 0; i < n; ++i )
    {
		long long int t,a,b;
		scanf("%lld %lld %lld", &t, &a, &b);
		if ( a == 1 && b == 0 )
		{
			alfa[ca] = t;
			++ca;
		}
		else if ( a == 0 && b == 1 )
		{
			beta[cb] = t;
			++cb;
		}
		else if ( a == 1 && b == 1 )
		{
			gamma[cg] = t;
			++cg;
		}
    }
    
    
    mergeSort(alfa,0,ca-1);
    mergeSort(beta,0,cb-1);
    mergeSort(gamma,0,cg-1);
    /*
	for ( i = 0; i < ca; ++i )
    {
		printf("%lld ", alfa[i]);
    }
    printf("\n");
    for ( i = 0; i < cb; ++i )
    {
		printf("%lld ", beta[i]);
    }
    printf("\n");
    for ( i = 0; i < cg; ++i )
    {
		printf("%lld ", gamma[i]);
    }
    printf("\n");
    */
    long long int ka = k;
    long long int kb = k;
    long long int total = 0;
    
    long long int ia = 0;
    long long int ib = 0;
    long long int ig = 0;
    
    long long int p = k-ca;
    long long int q = k-cb;
    long long int maxi = -1;
    if ( p > 0 || q > 0 )
    {
		if ( p >= q )
		{
			maxi = p;
		}
		else
		{
			maxi = q;
		}
    }
    
    if ( maxi > cg )
    {
		printf("-1\n");
    }
    else
    {
	    for ( i = 0; i < maxi; ++i )
	    {
			total += gamma[ig];
			++ig;
			ka -= 1;
			kb -= 1;
	    }
		//printf("total es %lld\n", total);
	    while ( (ka != 0 || kb != 0) && ig < cg )
	    {
			long long int sum = 0;
			if ( ia < ca && ka != 0 )
			{
				sum += alfa[ia];
			}

			if ( ib < cb && kb != 0 )
			{
				sum += beta[ib];
			}

			if ( sum <= gamma[ig] )
			{
				total += sum;
				ia += 1;
				ib += 1;
				ka -= 1;
				kb -= 1;
			}
			else
			{
				total += gamma[ig];
				ig += 1;
				ka -= 1;
				kb -= 1;
			}
		}

		if ( ka == 0 && kb == 0 )
		{
			printf("%lld\n", total);
		}
		else
		{
			if ( ka != 0 )
			{
				for ( i = ia; i < ia+ka; ++i )
				{
					total += alfa[i];
				}
			}

			if ( kb != 0 )
			{
				for ( i = ib; i < ib+kb; ++i )
				{
					total += beta[i];
				}
			}
			printf("%lld\n", total);
		}
	}
	
	//system("pause");
}
