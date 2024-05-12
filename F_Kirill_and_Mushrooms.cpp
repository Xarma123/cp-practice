#include <bits/stdc++.h>
using namespace std;
#define lol long long
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol t;
    cin >> t;
    while (t--)
    {
        lol n;
        cin >> n;
        lol a[n];
        pair<lol, lol> c[n];
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
            c[i].first = a[i];
            c[i].second = i;
        }
        lol b[n];
        for (lol i = 0; i < n; i++)
        {
            cin >> b[i];
            b[i]--;
        }
        sort(c, c + n);
        lol k = n;
        set<pair<lol, lol>> x;
        set<lol> av;
        lol mx = 0;
        lol mni = 0;
        for (lol i = 1; i <= n; i++)
        {
            if (i - 2 >= 0)
            {
                if (x.count({a[b[i - 2]], b[i - 2]}))
                {
                    x.erase({a[b[i - 2]], b[i - 2]});
                }
                av.insert(b[i - 2]);
            }
            while (x.size() < i && k > 0)
            {
                k--;
                if (av.count(c[k].second))
                    continue;
                x.insert(c[k]);
            }
            if (x.size() == i)
            {
                lol cs = (*x.begin()).first * 1ll * i;
                if (cs > mx)
                {
                    mx = cs;
                    mni = i;
                }
            }
                }
        cout << mx << " " << mni << '\n';
    }

    return 0;
}
