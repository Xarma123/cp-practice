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
        lol n, m, k, H;
        cin >> n >> m >> k >> H;
        lol ans = 0;
        lol h[n];
        for (lol i = 0; i < n; i++)
        {
            cin >> h[i];
            lol v = abs(h[i] - H);
            if (v == 0)
            {
                continue;
            }
            if (v % k == 0 && (v / k <= (m - 1)))
            {
                ans++;
            }
        }
        cout << ans << '\n';
    }
}