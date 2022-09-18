#include <bits/stdc++.h>
#define lol long long
using namespace std;

int main()
{
    lol t;
    cin >> t;
    while (t--)
    {
        lol n, k;
        cin >> n >> k;
        string a;
        cin >> a;
        map<char, lol> mp;
        for (lol i = 0; i < n; i++)
        {
            mp[a[i]]++;
        }
        lol pairs = 0;
        lol odds = 0;
        for (auto i = mp.begin(); i != mp.end(); i++)
        {
            pairs += (*i).second / 2;
            odds += (*i).second % 2;
        }
        lol ans = 2 * (pairs / k);
        odds += 2 * (pairs % k);
        if (odds >= k)
            ans++;
        cout << ans << endl;

        9
    }

    return 0;
}999