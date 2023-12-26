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
        lol n, c;
        cin >> n >> c;
        lol a[n];
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        lol s = a[0];
        vector<pair<lol, lol>> v;
        for (lol i = 1; i < n; i++)
        {
            v.push_back({a[i] - (i + 1) * 1ll * c, i});
        }
        sort(v.rbegin(), v.rend());
        bool ans = true;
        for (auto e : v)
        {
            if (e.first + s >= 0)
            {
                s += a[e.second];
            }
            else
                ans = false;
        }
        if (ans)
            cout << "Yes\n";
        else
            cout << "No\n";
    }

    return 0;
}
