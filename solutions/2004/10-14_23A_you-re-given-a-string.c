/* Codeforces 23A - You're Given a String...
 * https://codeforces.com/problemset/problem/23/A
 * rating: 1200 | tags: brute force, greedy
 * source: accepted submission #18609546 (GNU C) downloaded from Codeforces
 */

#include <stdio.h>

#include <string.h>



int main()

{

    int i, j, temp, ans=0;

    char s[101];

    scanf("%s",s);

    for(i=0;i<strlen(s);i++)

    {

        for(j=i+1;j<strlen(s);j++)

        {

            temp = 0;

            while(s[i+temp]==s[j+temp])

                temp++;

            if(temp>ans) ans=temp;

        }

    }

    printf("%d\n",ans);

    return 0;

}
