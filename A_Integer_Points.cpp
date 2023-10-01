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
        lol ev = 0, od = 0;
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
            if (a[i] % 2 == 0)
                ev++;
            else
                od++;
        }
        lol m;
        cin >> m;
        lol b[m];
        lol ans = 0;
        for (lol i = 0; i < m; i++)
        {
            cin >> b[i];
            if (b[i] % 2 == 0)
                ans += ev;
            else
                ans += od;
        }
        cout << ans << '\n';
    }
}