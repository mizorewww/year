/* Codeforces 115E - Linear Kingdom Races
 * https://codeforces.com/problemset/problem/115/E
 * rating: 2400 | tags: data structures, dp
 * source: accepted submission #700802 (GNU C) downloaded from Codeforces
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXN 400010

struct node
{
	int l, r, ls, rs;
	long long int val, max;
};

struct edge
{
	int l, r, c;
};

void sort (struct edge a[MAXN], int l, int r)
{
	int i, j, x;
	struct edge y;
	i = l; j = r; x = a[(l+r)/2].r;
	while (i <= j)
	{
		while (a[i].r < x) i++;
		while (a[j].r > x) j--;
		if (i <= j)
		{
			y = a[i]; a[i] = a[j]; a[j] = y;
			i++; j--;
		}
	}
	if (l < j) sort(a,l,j);
	if (i < r) sort(a,i,r);
}

static struct node a[MAXN];

void ChangeSeg (int point, int l, int r, long long int how)
{
	if ((a[point].l >= l) && (a[point].r <= r))
	{
		a[point].val += how;
		a[point].max += how;
		return;
	}
	if (a[a[point].ls].r >= l) ChangeSeg(a[point].ls,l,r,how);
	if (a[a[point].rs].l <= r) ChangeSeg(a[point].rs,l,r,how);
	if (a[a[point].ls].max > a[a[point].rs].max) a[point].max = a[a[point].ls].max;
	else a[point].max = a[a[point].rs].max;
	a[point].max += a[point].val;
}

int main ()
{
	int N, M;
	scanf("%d %d",&N,&M);
	static int data[MAXN];
	int i;
	for (i = 1; i <= N; i++) scanf("%d",&(data[i]));
	static struct edge rc[MAXN];
	for (i = 0; i < M; i++)
	{
		scanf("%d %d %d",&(rc[i].l),&(rc[i].r),&(rc[i].c));
	}
	sort(rc,0,M-1);
	static long long int dp[MAXN];
	long long int res = 0LL;
	dp[0] = 0LL;
	int r, w;
	a[0].l = 0;
	a[0].r = N-1;
	a[0].ls = -1;
	a[0].rs = -1;
	a[0].val = 0;
	a[0].max = 0;
	r = 0; w = 1;
	while (w > r)
	{
		if (a[r].r > a[r].l)
		{
			a[w].l = a[r].l;
			a[w].r = (a[r].l + a[r].r) / 2;
			a[w].ls = -1;
			a[w].rs = -1;
			a[w].val = 0;
			a[w].max = 0;
			a[r].ls = w;
			w++;
			a[w].l = a[w-1].r + 1;
			a[w].r = a[r].r;
			a[w].ls = -1;
			a[w].rs = -1;
			a[w].val = 0;
			a[w].max = 0;
			a[r].rs = w;
			w++;
		}
		r++;
	}
	int pos = 0;
	for (i = 1; i <= N; i++)
	{
		ChangeSeg(0,i-1,i-1,dp[i-1]);
		ChangeSeg(0,0,i-1,(long long int)(-data[i]));
		while ((pos < M) && (rc[pos].r == i))
		{
			ChangeSeg(0,0,rc[pos].l-1,(long long int)(rc[pos].c));
			pos++;
		}
		dp[i] = dp[i-1];
		if (a[0].max > dp[i]) dp[i] = a[0].max;
		if (dp[i] > res) res = dp[i];
	}
	printf("%I64i\n",res);
	return 0;
}
