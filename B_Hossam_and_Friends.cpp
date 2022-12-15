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
        map<lol, lol> mp;
        while (m--)
        {
            lol a, b;
            cin >> a >> b;
            if (a > b)
                swap(a, b);
            if (mp.count(a))
            {
                mp[a] = min(mp[a], b);
            }
            else
                mp[a] = b;
        }
        lol ans = 0;
        lol l = n + 1;
        for (lol i = n; i >= 1; i--)
        {
            if (mp.count(i))
                l = min(l, mp[i]);
            ans += l - i;
        }
        cout << ans << endl;
    }

    return 0;
}