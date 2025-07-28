/* Codeforces 576C - Points on Plane
 * https://codeforces.com/problemset/problem/576/C
 * rating: 2100 | tags: constructive algorithms, divide and conquer, geometry, greedy, sortings
 * source: accepted submission #12929831 (GNU C) downloaded from Codeforces
 */

#include "stdio.h"
#include "stdlib.h"

struct point {
  int id, x, y;                                
};

const int MAX = 1000;

int cmp(const void * first, const void * second) {
  struct point* f = (struct point*) first;
  struct point* s = (struct point*) second;
  int x1 = f->x / MAX, x2 = s->x / MAX;
  if (x1 != x2) {
    return x1 - x2;
  } 
  if (x1 % 2 == 0) {
    return f->y - s->y;
  } else {
    return s->y - f->y;
  }                    
}
                           
int main() {          
  int n;
  scanf("%d", &n);
  struct point * points = malloc(sizeof(struct point) * n);
  int i;
  for (i = 0; i < n; i++) {
    int foo, bar;
    scanf("%d %d", &foo, &bar);
    points[i].id = i + 1;
    points[i].x = foo;
    points[i].y = bar;
  }
  qsort(points, n, sizeof(struct point), cmp);
  for (i = 0; i < n; i++) {
    printf("%d ", points[i].id);
  }
  printf("\n");      
  free(points);
  return 0;
}
