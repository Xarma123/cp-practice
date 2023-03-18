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
        lol a[n / 2];
        set<lol> un;
        for (lol i = 1; i <= n; i++)
            un.insert(i);
        bool ans = true;
        map<lol, lol> place;
        for (lol i = 0; i < n / 2; i++)
            cin >> a[i];
        for (lol i = 0; i < n / 2 && ans; i++)
        {
            if (!un.count(a[i]))
            {
                ans = false;
                continue;
            }
            un.erase(a[i]);
        }
        for (lol i = n / 2 - 1; i >= 0 && ans; i--)
        {
            auto it = un.lower_bound(a[i]);
            if (it == un.begin())
            {
                ans = false;
                continue;
            }
            it--;
            place[i] = (*it);
            un.erase(it);
        }

        if (ans)
        {
            for (lol i = 0; i < n / 2; i++)
            {
                cout << min(place[i], a[i]) << " " << max(place[i], a[i]) << " ";
            }
            cout << '\n';
        }
        else
            cout << -1 << '\n';
    }

    return 0;
}