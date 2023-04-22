/* Codeforces 105C - Item World
 * https://codeforces.com/problemset/problem/105/C
 * rating: 2200 | tags: brute force, implementation, sortings
 * source: accepted submission #607683 (GNU C) downloaded from Codeforces
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXN 1005
#define MAXLEN 15

struct ite
{
	char name[MAXLEN];
	int val;
	int size;
};

struct bon
{
	char name[MAXLEN];
	char where[MAXLEN];
	int val;
};

void sort (struct bon a[MAXN], int l, int r)
{
	if (r <= l) return;
	int i, j, x;
	struct bon y;
	i = l; j = r; x = a[(l+r)/2].val;
	while (i <= j)
	{
		while (a[i].val > x) i++;
		while (a[j].val < x) j--;
		if (i <= j)
		{
			y = a[i]; a[i] = a[j]; a[j] = y;
			i++; j--;
		}
	}
	if (l < j) sort(a,l,j);
	if (i < r) sort(a,i,r);
}

int main ()
{
	static struct ite w[MAXN];
	int wc = 0;
	static struct ite a[MAXN];
	int ac = 0;
	static struct ite o[MAXN];
	int oc = 0;
	static struct bon g[MAXN];
	int gc = 0;
	static struct bon s[MAXN];
	int sc = 0;
	static struct bon p[MAXN];
	int pc = 0;
	static char name[MAXLEN];
	static char type[MAXLEN];
	static char useless[MAXLEN];
	int x, y, z, sz;
	int N, M;
	int S = 0;
	scanf("%d\n",&N);
	int i, j;
	for (i = 0; i < N; i++)
	{
		scanf("%s %s %d %d %d %d\n",name,type,&x,&y,&z,&sz);
		S += sz;
		if (type[0] == 'w')
		{
			memcpy(w[wc].name, name, sizeof(name));
			w[wc].val = x;
			w[wc].size = sz;
			wc++;
		}
		else if (type[0] == 'a')
		{
			memcpy(a[ac].name, name, sizeof(name));
			a[ac].val = y;
			a[ac].size = sz;
			ac++;
		}
		else
		{
			memcpy(o[oc].name, name, sizeof(name));
			o[oc].val = z;
			o[oc].size = sz;
			oc++;
		}
	}
	scanf("%d\n",&M);
	for (i = 0; i < M; i++)
	{
		scanf("%s %s %d %s\n",name,type,&sz,useless);
		if (type[0] == 'g')
		{
			memcpy(g[gc].name, name, sizeof(name));
			memcpy(g[gc].where, useless, sizeof(useless));
			g[gc].val = sz;
			gc++;
		}
		else if (type[0] == 's')
		{
			memcpy(s[sc].name, name, sizeof(name));
			memcpy(s[sc].where, useless, sizeof(useless));
			s[sc].val = sz;
			sc++;
		}
		else
		{
			memcpy(p[pc].name, name, sizeof(name));
			memcpy(p[pc].where, useless, sizeof(useless));
			p[pc].val = sz;
			pc++;
		}
	}
	static struct bon bg[MAXN];
	int bgc;
	if (S == M)
	{
		int res, resw, cnt, temp;

		bgc = 0;
		for (i = 0; i < gc; i++)
		{
			bg[bgc] = g[i];
			bgc++;
		}
		for (i = 0; i < sc; i++)
		{
			bg[bgc] = s[i];
			bgc++;
		}
		for (i = 0; i < pc; i++)
		{
			bg[bgc] = p[i];
			bgc++;
		}

		res = -1; resw = -1;
		for (i = 0; i < wc; i++)
		{
			temp = w[i].val;
			for (j = 0; j < gc; j++)
			{
				if (strcmp(w[i].name, g[j].where) == 0) temp += g[j].val;
			}
			if (temp > res)
			{
				res = temp;
				resw = i;
			}
		}
		cnt = 0;
		for (i = 0; i < bgc; i++)
		{
			if (strcmp(w[resw].name, bg[i].where) == 0) cnt++;
		}
		printf("%s %d",w[resw].name,cnt);
		for (i = 0; i < bgc; i++)
		{
			if (strcmp(w[resw].name, bg[i].where) == 0) printf(" %s",bg[i].name);
		}
		printf("\n");

		res = -1; resw = -1;
		for (i = 0; i < ac; i++)
		{
			temp = a[i].val;
			for (j = 0; j < sc; j++)
			{
				if (strcmp(a[i].name, s[j].where) == 0) temp += s[j].val;
			}
			if (temp > res)
			{
				res = temp;
				resw = i;
			}
		}
		cnt = 0;
		for (i = 0; i < bgc; i++)
		{
			if (strcmp(a[resw].name, bg[i].where) == 0) cnt++;
		}
		printf("%s %d",a[resw].name,cnt);
		for (i = 0; i < bgc; i++)
		{
			if (strcmp(a[resw].name, bg[i].where) == 0) printf(" %s",bg[i].name);
		}
		printf("\n");

		res = -1; resw = -1;
		for (i = 0; i < oc; i++)
		{
			temp = o[i].val;
			for (j = 0; j < pc; j++)
			{
				if (strcmp(o[i].name, p[j].where) == 0) temp += p[j].val;
			}
			if (temp > res)
			{
				res = temp;
				resw = i;
			}
		}
		cnt = 0;
		for (i = 0; i < bgc; i++)
		{
			if (strcmp(o[resw].name, bg[i].where) == 0) cnt++;
		}
		printf("%s %d",o[resw].name,cnt);
		for (i = 0; i < bgc; i++)
		{
			if (strcmp(o[resw].name, bg[i].where) == 0) printf(" %s",bg[i].name);
		}
		printf("\n");
	}
	else
	{
		sort(g,0,gc-1);
		sort(s,0,sc-1);
		sort(p,0,pc-1);
		int temp, lim;

		int resw = -1;
		int resw_w = -1;
		int resw_c = 0;
		for (i = 0; i < wc; i++)
		{
			temp = w[i].val;
			lim = w[i].size;
			if (gc < lim) lim = gc;
			for (j = 0; j < lim; j++) temp += g[j].val;
			if (temp > resw)
			{
				resw = temp;
				resw_w = i;
				resw_c = lim;
			}
		}

		int resa = -1;
		int resa_w = -1;
		int resa_c = 0;
		for (i = 0; i < ac; i++)
		{
			temp = a[i].val;
			lim = a[i].size;
			if (sc < lim) lim = sc;
			for (j = 0; j < lim; j++) temp += s[j].val;
			if (temp > resa)
			{
				resa = temp;
				resa_w = i;
				resa_c = lim;
			}
		}

		int reso = -1;
		int reso_w = -1;
		int reso_c = 0;
		for (i = 0; i < oc; i++)
		{
			temp = o[i].val;
			lim = o[i].size;
			if (pc < lim) lim = pc;
			for (j = 0; j < lim; j++) temp += p[j].val;
			if (temp > reso)
			{
				reso = temp;
				reso_w = i;
				reso_c = lim;
			}
		}

		bgc = 0;
		for (i = resw_c; i < gc; i++)
		{
			bg[bgc] = g[i];
			bgc++;
		}
		for (i = resa_c; i < sc; i++)
		{
			bg[bgc] = s[i];
			bgc++;
		}
		for (i = reso_c; i < pc; i++)
		{
			bg[bgc] = p[i];
			bgc++;
		}

		lim = resw_c + bgc;
		if (w[resw_w].size < lim) lim = w[resw_w].size;
		printf("%s %d",w[resw_w].name,lim);
		for (i = 0; i < resw_c; i++) printf(" %s",g[i].name);
		for (i = resw_c; i < lim; i++)
		{
			bgc--;
			printf(" %s",bg[bgc].name);
		}
		printf("\n");

		lim = resa_c + bgc;
		if (a[resa_w].size < lim) lim = a[resa_w].size;
		printf("%s %d",a[resa_w].name,lim);
		for (i = 0; i < resa_c; i++) printf(" %s",s[i].name);
		for (i = resa_c; i < lim; i++)
		{
			bgc--;
			printf(" %s",bg[bgc].name);
		}
		printf("\n");
		
		lim = reso_c + bgc;
		if (o[reso_w].size < lim) lim = o[reso_w].size;
		printf("%s %d",o[reso_w].name,lim);
		for (i = 0; i < reso_c; i++) printf(" %s",p[i].name);
		for (i = reso_c; i < lim; i++)
		{
			bgc--;
			printf(" %s",bg[bgc].name);
		}
		printf("\n");
	}
	return 0;
}
