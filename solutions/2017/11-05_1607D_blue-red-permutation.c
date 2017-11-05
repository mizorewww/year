/* Codeforces 1607D - Blue-Red Permutation
 * https://codeforces.com/problemset/problem/1607/D
 * rating: 1300 | tags: greedy, math, sortings
 * source: accepted submission #134105447 (GNU C11) downloaded from Codeforces
 */

#define __USE_MINGW_ANSI_STDIO 0
#include <stdio.h>

// RNG
// DEPENDENCIES:
// 
#include <sys/time.h>
unsigned int X;

// Initialises X to a random number.
void __attribute__((constructor)) setRandSeed(); 
void setRandSeed() {
    struct timeval now;
    gettimeofday(&now, 0);
    X = now.tv_sec ^ now.tv_usec | 1;
    return;
}

// Returns an pseudo random int in the range [0, max)
static inline int pRand(int max) {
    return (X *= 3) % max;
}
// END RNG

// SHUFFLESORT
// DEPENDENCIES:
// RNG
#include <stdlib.h>
#include <string.h>

// Self explanatory - shuffle an array of some len in-place.
void shuffle(void *arrayPointer, int len, int size) {
	// Cast to char for byte-wise copying 
    char *array = (char *) arrayPointer;
    // Loop backwards through the array and find a random indice to swap into this position.
    char tmp[size];
    for (int i = len - 1; i >= 1; --i) {
        int randIndice = pRand(i);
        memcpy(tmp, &array[i * size], size);
        memcpy(&array[i * size], &array[randIndice * size], size);
        memcpy(&array[randIndice * size], tmp, size);
    }
    return;
}

// Usage is similar to that of qsort.
void sort(void *array, int num, int size, int (*cmp)(const void *, const void *)) {
    shuffle(array, num, size);
    qsort(array, num, size, cmp);
    return;
}
// END SHUFFLESORT

int asc(const void *pa, const void *pb) { return *(int *)pa - *(int *)pb; }

#define maxN 200000
#include <stdbool.h>

int pos[maxN];
int neg[maxN];
int a[maxN];
char s[maxN + 1];

void testcase() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("%d", &a[i]);
    scanf("%s", s);
    int posLen = 0, negLen = 0;
    for (int i = 0; i < n; ++i)
        if (s[i] == 'B')
            neg[negLen++] = a[i];
        else
            pos[posLen++] = a[i];
    sort(neg, negLen, sizeof(neg[0]), asc);
    sort(pos, posLen, sizeof(pos[0]), asc);
    //
    int _n = 0, _p = 0;
    bool isPermutable = true;
    for (int i = 1; i <= n; ++i) {
        if (_n == negLen) {
            // neg exhausted, check all pos
            if (pos[_p] <= i) {
                // good
                ++_p;
            } else {
                isPermutable = false;
                break;
            }
        } else {
            // neg not exhausted, check negs
            if (neg[_n] >= i) {
                // good
                ++_n;
            } else {
                isPermutable = false;
                break;
            }
        }
    }
    if (isPermutable) printf("YES\n");
    else printf("NO\n");
    return;
}

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; ++i) testcase();
    return 0;
}
