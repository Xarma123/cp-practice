#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n, k;
    cin >> n >> k;
    lol a[n];
    for (lol i = 0; i < n; i++)
    {
        cin >> a[i];
        a[i] = a[i] % k;
    }

    lol ans = 0;

    map<lol, lol> mp;
    for (lol i = 0; i < n; i++)
    {
        if (a[i] == 0)
        {
            if (mp[0])
            {
                ans++;
                mp[0]--;
            }
            else
                mp[0]++;
        }
        else if (mp[k - a[i]])
        {
            ans++;
            mp[k - a[i]]--;
        }
        else
            mp[a[i]]++;
    }
    cout << 2 * 1ll * ans;

    return 0;
}