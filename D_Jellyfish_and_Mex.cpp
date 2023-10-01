#include <bits/stdc++.h>
using namespace std;
#define lol long long
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
        sort(a, a + n);
        if (a[0] != 0)
        {
            cout << 0 << '\n';
            continue;
        }
        vector<lol> c;
        c.push_back(a[0]);
        for (lol i = 1; i < n; i++)
        {
            if (a[i] == a[i - 1] || a[i] == a[i - 1] + 1)
            {
                c.push_back(a[i]);
            }
            else
                break;
        }
        map<lol, lol> f;
        for (lol i = 0; i < c.size(); i++)
        {
            f[c[i]]++;
        }
        set<pair<lol, lol>> x;
        for (auto e : f)
        {
            x.insert({e.second, e.first});
        }
        lol mex = c.back() + 1;
        lol ans = 0;
        for (lol i = 0; i < n; i++)
        {
            while (!x.empty() && (*x.begin()).second > mex)
                x.erase(x.begin());
            if (x.size() != 0)
            {
                pair<lol, lol> p = (*x.begin());
                x.erase(x.begin());
                p.first--;
                cout << p.second << endl;
                if (p.first == 0)
                    mex = p.second;
                else
                    x.insert({p});
            }
            ans += mex;
        }
        cout << ans << '\n';
    }
}