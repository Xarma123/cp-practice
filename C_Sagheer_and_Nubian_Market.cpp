#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n, s;
    cin >> n >> s;
    lol a[n];
    for (lol i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    lol st = 0, e = n + 1;
    while (st != e - 1)
    {
        lol m = (st + e) / 2;
        if (m == 0)
            st = m;
        else if (m == n + 1)
            e = m;
        else
        {
            lol b[n];
            for (lol i = 0; i < n; i++)
            {
                b[i] = a[i] + (i + 1) * 1ll * m;
            }
            sort(b, b + n);
            lol c = 0;
            for (lol i = 0; i < m; i++)
            {
                c += b[i];
            }
            if (c <= s)
                st = m;
            else
                e = m;
        }
    }
    lol b[n];
    for (lol i = 0; i < n; i++)
    {
        b[i] = a[i] + (i + 1) * 1ll * st;
    }
    sort(b, b + n);
    lol c = 0;
    for (lol i = 0; i < st; i++)
    {
        c += b[i];
    }
    cout << st << " " << c;

    return 0;
}