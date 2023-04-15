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
        lol n, m;
        cin >> n >> m;
        vector<lol> k(n);
        for (lol i = 0; i < n; i++)
        {
            cin >> k[i];
        }
        sort(k.begin(), k.end());
        while (m--)
        {
            lol a, b, c;
            cin >> a >> b >> c;
            lol st = lower_bound(k.begin(), k.end(), b) - k.begin();
            bool f = false;
            if (st >= 0 && st < k.size())
            {
                if ((b - k[st]) * 1ll * (b - k[st]) - 4ll * a * 1ll * c < 0)
                    cout << "YES\n", cout << k[st] << '\n', f = true;
            }
            st--;
            if (st >= 0 && st < k.size() && !f)
            {
                if ((b - k[st]) * 1ll * (b - k[st]) - 4ll * a * 1ll * c < 0)
                    cout << "YES\n", cout << k[st] << '\n', f = true;
            }
            if (!f)
                cout << "NO" << '\n';
        }
    }

    return 0;
}