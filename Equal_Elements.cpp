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
        lol a[n];
        map<lol, lol> mp;
        lol ans = n;
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
            mp[a[i]]++;
            ans = min(ans, n - mp[a[i]]);
        }
        cout << ans << endl;
    }

    return 0;
}