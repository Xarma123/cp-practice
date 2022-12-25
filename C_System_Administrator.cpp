#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n, m, v;
    cin >> n >> m >> v;
    if (m >= n - 1 && m <= n-1+((n-2)*1ll*(n-3)/2))
    {
        for (lol i = 1; i <= n; i++)
        {
            if (i != v)
                cout << v << " " << i << '\n';
        }
        m -= n - 1;
        lol sv;
        if (v - 1 >= 1)
            sv = v - 1;
        else if (v + 1 <= n)
            sv = v + 1;
        set<lol> x;
        for (lol i = 1; i <= n && (x.size() * 1ll * (x.size() - 1) / 2) < m; i++)
        {
            if (i != v && i != sv)
            {
                x.insert(i);
            }
        }
        while (m > 0 && x.size())
        {
            lol one = (*x.begin());
            x.erase(x.begin());
            for (auto i = x.begin(); i != x.end() && m > 0; i++, m--)
            {
                cout << one << " " << (*i) << '\n';
            }
        }
    }
    else
        cout << -1;

    return 0;
}