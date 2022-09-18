#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n;
    cin >> n;
    lol a[n];
    for (lol i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    map<lol, lol> mp;
    lol s = 0;
    mp[a[0]]++;
    lol ans = 1;
    for (lol i = 1; i < n; i++)
    {
        mp[a[i]]++;
        while (mp.size() > 2)
        {
            mp[a[s]]--;
            if (mp[a[s]] == 0)
            {
                mp.erase(a[s]);
            }
            s++;
        }
        if (mp.size() <= 2)
        {
            ans = max(ans, i - s + 1);
        }
    }

    cout << ans;

    return 0;
}