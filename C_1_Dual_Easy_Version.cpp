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
        lol mx = 0;
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
            if (a[i] > a[mx])
            {
                mx = i;
            }
        }
        if (n == 1)
            cout << 0 << '\n';
        else if (a[mx] > 0)
        {
            vector<pair<lol, lol>> v;

            while (a[mx] < 20ll)
            {
                v.push_back({mx + 1, mx + 1});
                a[mx] = a[mx] * 2ll;
            }
            for (lol i = 0; i < n; i++)
            {
                while (a[i] < 0)
                {
                    v.push_back({i + 1, mx + 1});
                    a[i] += a[mx];
                }
            }
            for (lol i = 1; i < n; i++)
            {
                if (i == 1)
                {
                    v.push_back({i + 1, mx + 1});
                }
                else
                    v.push_back({i + 1, i});
            }
            cout << v.size() << '\n';
            for (auto e : v)
                cout << e.first << " " << e.second << '\n';
        }
        else
        {
            mx = 0;
            for (lol i = 0; i < n; i++)
            {
                if (a[i] < a[mx])
                    i = mx;
            }
            vector<pair<lol, lol>> v;
            for (lol i = n - 1; i >= 0; i--)
            {
                if (i == n - 1)
                {
                    v.push_back({i + 1, mx + 1});
                }
                else
                    v.push_back({i + 1, i + 2});
            }
            cout << v.size() << '\n';
            for (auto e : v)
                cout << e.first << " " << e.second << '\n';
        }
    }
}