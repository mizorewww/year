/* Codeforces 1114B - Yet Another Array Partitioning Task
 * https://codeforces.com/problemset/problem/1114/B
 * rating: 1500 | tags: constructive algorithms, greedy, sortings
 * source: accepted submission #49728399 (GNU C11) downloaded from Codeforces
 */

#include<stdlib.h> 
#include<stdio.h> 
  
// Merges two subarrays of arr[]. 
// First subarray is arr[l..m] 
// Second subarray is arr[m+1..r] 
void merge(int arr[], int l, int m, int r) 
{ 
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 =  r - m; 
  
    /* create temp arrays */
    int L[n1], R[n2]; 
  
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
void mergeSort(int arr[], int l, int r) 
{ 
    if (l < r) 
    { 
        // Same as (l+r)/2, but avoids overflow for 
        // large l and h 
        int m = l+(r-l)/2; 
  
        // Sort first and second halves 
        mergeSort(arr, l, m); 
        mergeSort(arr, m+1, r); 
  
        merge(arr, l, m, r); 
    } 
} 
  
/* UTILITY FUNCTIONS */
/* Function to print an array */
void printArray(int A[], int size) 
{ 
    int i; 
    for (i=0; i < size; i++) 
        printf("%d ", A[i]); 
    printf("\n"); 
}
int main()
{
	int n,m,k;
	scanf("%d %d %d",&n,&m,&k);
	int arr[n];
	int i;
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	int a[n];
	for(i=0;i<n;i++)
	{
		a[i]=arr[i];
	}
	mergeSort(a,0,n-1);
	long long int pr,sum=0;
	pr=m*k;
	for(i=0;i<pr;i++)
	{
		sum=sum+a[n-1-i];
	}
	printf("%lld\n",sum);
	long long int x,y,z;
	//x=a[n-1];
	y=a[n-pr];
	long long int h=0,j=0;
//	x=k;
	while(1)
	{
		if(a[n-pr+z]==a[n+1-pr+z])
		{
			j++;
		}
		else
		{
			break;
		}
		z++;
	}
	j++;
	x=0;

int answ[k];
	long long int l=0;
	for(i=0;i<n;i++)
	{
	//	x--;
	//	if(x==0)
	//{
	//		break;
	//}
	//	else
	//	{
//	printf("%d",k);
		if(k>1)
		{
		if(arr[i]>y)
		{
			l++;
			if(l==m)
			{
				printf("%d ",i+1);
				//answ[x]=i+1;
				x++;
				l=0;
				k--;
			}
		}
		else if((arr[i]==y) && (j!=0))
		{
			j--;
			l++;
			if(l==m)
			{
				printf("%d ",i+1);
				//answ[x]=i+1;
				x++;
				l=0;
				k--;
			}
		}
		}
	//	k--;
		}
	//	}
//	for(i=0;i<(k-1);i++)
//	{
//		printf("%d ",answ[i]);
//`	}
}
