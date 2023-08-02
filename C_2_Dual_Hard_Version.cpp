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
        lol ne = 0, p = 0;
        lol mx = 0;
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
            if (a[i] < 0)
                ne++;
            else if (a[i] > 0)
                p++;
            if ((long long)abs(a[i]) > (long long)abs(a[mx]))
                mx = i;
        }
        if (a[mx] <= 0)
        {
            ne += 5;
        }
        else
            p += 5;
        if (p <= ne)
        {
            vector<pair<lol, lol>> v;
            lol mx = 0;
            for (lol i = 0; i < n; i++)
            {
                if (a[i] < a[mx])
                    mx = i;
            }
            for (lol i = 0; i < n; i++)
            {
                while (a[mx] + a[i] > 0)
                {
                    v.push_back({mx + 1, mx + 1});
                    a[mx] = 2ll * a[mx];
                }
                if (a[i] > 0)
                {
                    v.push_back({i + 1, mx + 1});
                }
            }
            for (lol i = n - 2; i >= 0; i--)
            {
                v.push_back({i + 1, i + 2});
            }
            cout << v.size() << '\n';
            for (auto e : v)
                cout << e.first << " " << e.second << '\n';
        }
        else
        {
            vector<pair<lol, lol>> v;
            lol mx = 0;
            for (lol i = 0; i < n; i++)
            {
                if (a[i] > a[mx])
                    mx = i;
            }
            for (lol i = 0; i < n; i++)
            {
                while (a[mx] + a[i] < 0)
                {
                    v.push_back({mx + 1, mx + 1});
                    a[mx] = 2ll * a[mx];
                }
                if (a[i] < 0)
                {
                    v.push_back({i + 1, mx + 1});
                }
            }
            for (lol i = 1; i < n; i++)
            {
                v.push_back({i + 1, i});
            }
            cout << v.size() << '\n';
            for (auto e : v)
                cout << e.first << " " << e.second << '\n';
        }
    }
}