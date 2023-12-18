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
        lol n;
        cin >> n;
        lol a[n];
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        lol k[n];
        lol y[n];
        for (lol i = 0; i < n; i++)
        {
            lol v = a[i];
            k[i] = 0;
            while (v % 2 == 0)
            {
                k[i]++;
                v /= 2;
            }
            y[i] = v;
        }
        map<lol, map<lol, lol>> mp;
        lol ans = 0;
        for (lol i = 0; i < n; i++)
        {
            ans += mp[y[i]][a[i] - k[i]];
            mp[y[i]][a[i] - k[i]]++;
        }
        cout << ans << '\n';
    }

    return 0;
}
