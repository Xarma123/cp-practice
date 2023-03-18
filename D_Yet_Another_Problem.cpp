#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n, q;
    cin >> n >> q;
    lol a[n];
    for (lol i = 0; i < n; i++)
        cin >> a[i];
    lol px[n + 1];
    px[0] = 0;
    for (lol i = 0; i < n; i++)
        px[i + 1] = a[i] ^ px[i];
    lol sum[n + 1];
    sum[0] = 0;
    for (lol i = 0; i < n; i++)
        sum[i + 1] = a[i] + sum[i];
    map<lol, vector<lol>> mp[2];
    lol v = 0;
    for (lol i = 0; i < n; i++)
    {
        v ^= a[i];

        mp[((i + 1) % 2)][v].push_back(i + 1);
    }

    while (q--)
    {
        lol l, r;
        cin >> l >> r;
        if ((r - l + 1) % 2 != 0)
        {
            lol tot = px[r] - px[l - 1];
            if (tot != 0)
            {
                cout << -1 << '\n';
            }
            else if (sum[r] - sum[l - 1] == 0)
            {
                cout << 0 << '\n';
            }
            else
                cout << 1 << '\n';
        }
        else
        {
            lol tot = px[r] - px[l - 1];
            if (tot != 0)
            {
                cout << -1 << '\n';
            }
            else if (sum[r] - sum[l - 1] == 0)
                cout << 0 << '\n';
            else if (a[l - 1] == 0 || a[r - 1] == 0)
            {
                cout << 1 << '\n';
            }
            else
            {
                lol j = lower_bound(mp[l % 2][px[l - 1]].begin(), mp[l % 2][px[l - 1]].end(), l) - mp[l % 2][px[l - 1]].begin();
                if (j < mp[l % 2][px[l - 1]].size() && mp[l % 2][px[l - 1]][j] <= r)
                {

                    cout << 2 << '\n';
                }
                else
                    cout << -1 << '\n';
            }
        }
    }

    return 0;
}