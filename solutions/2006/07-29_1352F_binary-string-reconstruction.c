/* Codeforces 1352F - Binary String Reconstruction
 * https://codeforces.com/problemset/problem/1352/F
 * rating: 1500 | tags: constructive algorithms, dfs and similar, math
 * source: accepted submission #79551548 (GNU C11) downloaded from Codeforces
 */

#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<limits.h>
#define MOD 1000000007

int *array;

int min(int a, int b) {
    return a<b?a:b;
}

int max(int a, int b) {
    return a>b?a:b;
}

int compare(const void* a, const void* b) {
    return *(int*)a-*(int*)b;
}

int cmp(const void *a, const void *b){
    int ia = *(int *)a;
    int ib = *(int *)b;
    return array[ia] < array[ib] ? -1 : array[ia] > array[ib];
}

int abs(int n) {
    if(n < 0)
        return n*(-1);
    return n;
}

void swap(int *a, int *b) {
    *a = (*a)^(*b);
    *b = (*a)^(*b);
    *a = (*a)^(*b);
}

int binSearch(int a[], int x, int l, int r) {
    if(r >= l) {
        int mid = l + ((r-l)>>1);
        if(a[mid] == x)
            return mid;
        if(a[mid] > x) {
            return binSearch(a, x, l, mid-1);
        }
        else if(a[mid] < x) {
            return binSearch(a, x, mid+1, r);
        }
    }
    return -1;
}

int isRound(int n) {
    int count=0, count_0=0;
    while(n) {
        int x = n%10;
        
        // printf("%d\n", n%10);
        if(x == 0)
            count_0++;
        else
            count++;
        n /= 10;
    }
    if(count == 1)
        return 1;
    return 0;
}

int findRound(int n) {
    int count=0;
    int temp = n;
    while(temp) {
        count++;        
        temp /= 10;
    }
    int power=1;
    for(int i=0;i<count-1;i++)
        power *= 10;
    int res = n - (n%power);
    return res;
}

void testCase() {
    int i, x, y, z;
    scanf("%d%d%d", &x, &y, &z);
    if(x > 0) {
        for(i=0;i<x;i++) {
            printf("0");
        }
        if(y == 0) {
            printf("0");
            return;
        }
    }
    if(y > 0) {
        int flag = 0;
        if(y%2 == 0) {
            flag = 1;
            y--;
        }
        for(i=0;i<(y+1)/2;i++) {
            printf("01");
        }
        if(flag)
            y++;
        if(z == 0 && flag) {
            printf("0");
        }
    }
    if(z > 0) {
        for(i=0;i<z;i++) {
            printf("1");
        }
        if(y == 0) {
            printf("1");
        }
        if(y%2 == 0 && y != 0) {
            printf("0");
        }
    }
}

int main() {
    int t=1;
    scanf("%d", &t);
    while(t--) {
        testCase();
        printf("\n");
    }
    return 0;
}
