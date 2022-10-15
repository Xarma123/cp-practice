#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n, x;
    cin >> n >> x;
    lol a[n];
    lol mn = LONG_LONG_MAX;
    for (lol i = 0; i < n; i++)
    {
        cin >> a[i];

        mn = min(mn, a[i]);
    }
    for (lol i = 0; i < n; i++)
    {
        a[i] -= mn;
    }
    lol X = x - 1;

    x--;
    lol st;
    while (1)
    {
        if (a[x] == 0)
        {
            st = x;
            break;
        }
        x--;
        if (x < 0)
        {
            x = n - 1;
        }
    }
    a[st] += mn * 1ll * n;
    if (st == X)
    {
        for (lol i = 0; i < n; i++)
        {
            cout << a[i] << " ";
        }
    }
    else
    {
        lol q = st;
        st++;
        st %= n;

        while (1)
        {
            a[st]--;
            a[q]++;
            if (st == X)
                break;
            st++;
            st %= n;
        }

        for (lol i = 0; i < n; i++)
        {
            cout << a[i] << " ";
        }
    }

    return 0;
}