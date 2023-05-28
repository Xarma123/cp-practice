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
        cout << "+ " << n + 1 << endl;
        lol q;
        cin >> q;

        if (q == -2)
            return 0;
        cout << "+ " << n << endl;
        cin >> q;

        if (q == -2)
            return 0;
        vector<lol> c;
        lol a = n / 2;
        lol b = n / 2 + 1;
        if (n % 2 == 1)
        {
            a++;
            b++;
            c.push_back(a);
            a--;
        }
        bool f = true;
        while (a >= 1 || b <= n)
        {
            if (f)
            {
                c.push_back(a);
                a--;
                f = false;
            }
            else
            {
                c.push_back(b);
                b++;
                f = true;
            }
        }
        lol mxd = 0;
        lol p;
        for (lol i = 2; i <= n; i++)
        {
            cout << "? " << i << " " << 1 << endl;
            lol r;
            cin >> r;
            if (r > mxd)
            {
                mxd = r;
                p = i;
            }
        }
        vector<pair<lol, lol>> v;
        v.push_back({0, p});
        for (lol i = 1; i <= n; i++)
        {
            if (i == p)
                continue;
            cout << "? " << i << " " << p << endl;
            lol r;
            cin >> r;
            v.push_back({r, i});
        }
        sort(v.begin(), v.end());
        lol ans[n + 1];
        for (lol i = 0; i < n; i++)
        {
            ans[v[i].second] = c[i];
        }
        cout << "! ";
        for (lol i = 1; i <= n; i++)
        {
            cout << ans[i] << " ";
        }
        for (lol i = 0; i < n; i++)
        {
            ans[v[i].second] = c[n - 1 - i];
        }
        for (lol i = 1; i <= n; i++)
        {
            if (i < n)
                cout << ans[i] << " ";
            else
                cout << ans[i] << endl;
        }
        cin >> q;
        if (q != 1)
            return 0;
    }

    return 0;
}