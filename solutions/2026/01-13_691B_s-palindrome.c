/* Codeforces 691B - s-palindrome
 * https://codeforces.com/problemset/problem/691/B
 * rating: 1600 | tags: implementation, strings
 * source: accepted submission #19422310 (GNU C) downloaded from Codeforces
 */

#include<stdio.h>

#include<string.h>

int main()

{

    int i,d,j;

    char st[1005],a[17]="AHIMOoTUVvWwXxY";

    gets(st);

    d=strlen(st);

    for(i=0;i<(d+1)/2;i++)

    {

        for(j=0;j<15;j++)

        {

            if(st[i]==a[j]&&st[d-i-1]==a[j])

                break;

        }

        if(j==15)

        {

            if((st[i]=='b'&&st[d-i-1]=='d')||(st[i]=='d'&&st[d-i-1]=='b')||(st[i]=='p'&&st[d-i-1]=='q')||(st[i]=='q'&&st[d-i-1]=='p'));

            else

                break;

        }

    }

    if(i==(d+1)/2)

        printf("TAK");

    else

        printf("NIE");

}
