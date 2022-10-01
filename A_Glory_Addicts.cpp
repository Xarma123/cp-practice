#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol t;
    cin >> t;
    while (t--)
    {
        lol n;
        cin >> n;
        lol a[n];
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        vector<lol> z, o;
        for (lol i = 0; i < n; i++)
        {
            lol q;
            cin >> q;
            if (a[i])
                o.push_back(q);
            else
                z.push_back(q);
        }
        sort(o.begin(), o.end());
        sort(z.begin(), z.end());
        lol ans = 0;
        if (o.size() == 0 || z.size() == 0)
        {
            for (lol i = 0; i < o.size(); i++)
            {
                ans += o[i];
            }
            for (lol i = 0; i < z.size(); i++)
            {
                ans += z[i];
            }
        }
        else if (abs((long long)(o.size() - z.size())))
        {
            lol mn = min(o.size(), z.size());
            for (lol i = 0; i < o.size(); i++)
            {
                if (i < o.size() - mn)
                    ans += o[i];
                else
                    ans += 2 * 1ll * o[i];
            }
            for (lol i = 0; i < z.size(); i++)
            {
                if (i < z.size() - mn)
                    ans += z[i];
                else
                    ans += 2 * 1ll * z[i];
            }
        }
        else
        {
            for (lol i = 0; i < o.size(); i++)
            {
                ans += 2 * 1ll * o[i];
            }
            for (lol i = 0; i < z.size(); i++)
            {
                ans += 2 * 1ll * z[i];
            }
            ans -= min(o[0], z[0]);
        }
        cout << ans << endl;
    }

    return 0;
}