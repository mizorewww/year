/* Codeforces 1095E - Almost Regular Bracket Sequence
 * https://codeforces.com/problemset/problem/1095/E
 * rating: 1900 | tags: implementation
 * source: accepted submission #47585049 (GNU C11) downloaded from Codeforces
 */

#include <stdio.h>

#define maxn 1000010
char s[maxn];
int c[maxn];
int n;

int min(int a, int b) { return a < b ? a : b; }

int check()
{
    int i, low, ret;
    scanf("%d\n%s", &n, s);
    if (n & 1)
        return 0;
    c[0] = 0;
    low = 0;
    for (i = 0; i < n; i++)
    {
        if (s[i] == '(')
            c[i + 1] = c[i] + 1;
        else
            c[i + 1] = c[i] - 1;
        low = min(low, c[i + 1]);
    }
    if (c[n] == 2)
    {
        if (low < 0)
            return 0;
        ret = 0;
        for (i = n; i > 0; i--)
        {
            if (c[i] < 2)
                break;
            if (s[i - 1] == '(')
                ret++;
        }
        return ret;
    }
    else if (c[n] == -2)
    {
        if (low < -2)
            return 0;
        ret = 0;
        for (i = 0; i < n; i++)
        {
            if (c[i] < 0)
                break;
            if (s[i] == ')')
                ret++;
        }
        return ret;
    }
    else
    {
        return 0;
    }
}

int main()
{
    int r;
    r = check();
    printf("%d", r);
}
