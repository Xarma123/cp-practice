#include <stdio.h>
int n, a[255], b[255], r;
char s[100010], t[100010];
int main()
{   ///steal
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%s%s", s, t);
    for (int i = 0; s[i]; i++)
        a[s[i]]++;
    for (int i = 0; t[i]; i++)
        b[t[i]]++;
    for (int i = 'A'; i <= 'Z'; i++)
        r += a[i] > b[i] ? a[i] - b[i] : b[i] - a[i];
    for (int i = 0; s[i]; i++)
        if (a[s[i]] > b[s[i]])
        {
            for (int p = 'A'; p <= 'Z'; p++)
                if (p == s[i] && a[p] > 0 && b[p] > 0)
                {
                    --a[p];
                    --b[p];
                    break;
                }
                else if (b[p] > a[p])
                {
                    --a[s[i]];
                    ++a[p];
                    s[i] = p;
                    break;
                }
        }
    printf("%d\n%s", r / 2, s);
    return 0;
}
