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
        lol n, m, k;
        cin >> n >> m >> k;
        lol h[n];
        for (lol i = 0; i < n; i++)
        {
            cin >> h[i];
        }
        bool ans = true;
        for (lol i = 1; i < n; i++)
        {
            lol pv = max(h[i] - k, 0ll);
            if (h[i - 1] >= pv)
            {
                m += h[i - 1] - pv;
            }
            else if (m >= pv - h[i - 1])
            {
                m -= pv - h[i - 1];
            }
            else
            {
                ans = false;
            }
        }
        if (ans)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}