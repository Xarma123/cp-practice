#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n, m, q;
    cin >> n >> m >> q;
    string a[n];
    for (lol i = 0; i < n; i++)
        cin >> a[i];
    lol star = 0;
    for (lol i = 0; i < n; i++)
        for (auto e : a[i])
            if (e == '*')
                star++;
    lol c = star / n;
    lol r = star % n;
    lol ans = 0;
    for (lol i = 0; i < n; i++)
    {
        for (lol j = 0; j < m; j++)
        {
            if (a[i][j] == '*')
            {
                if (j > c)
                {
                    ans++;
                }
                else if (j == c)
                {
                    if (i >= r)
                    {
                        ans++;
                    }
                }
            }
        }
    }
    while (q--)
    {
        lol i, j;
        cin >> i >> j;
        i--, j--;
        if (a[i][j] == '*')
        {
            if (j > c)
            {
                ans--;
            }
            else if (j == c)
            {
                if (i >= r)
                {
                    ans--;
                }
            }
            a[i][j] = '.';
            r--;
            if (r < 0)
            {
                r = n - 1;
                c--;
            }
            if (a[r][c] == '*')
                ans++;
        }
        else
        {
            if (a[r][c] == '*')
                ans--;
            r++;
            if (r == n)
            {
                r = 0;
                c++;
            }
            if (j > c)
            {
                ans++;
            }
            else if (j == c)
            {
                if (i >= r)
                {
                    ans++;
                }
            }
            a[i][j] = '*';
        }
        cout << ans << '\n';
    }

    return 0;
}