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
    lol b[n];
    for (lol i = 0; i < n; i++)
    {
        cin >> a[i];
        b[i] = a[i];
    }
    sort(b, b + n);
    map<lol, lol> mp;
    lol ans = 0;
    for (lol i = 0; i < n; i++)
    {
        mp[b[i]]--;
        mp[a[i]]++;
        if (mp[a[i]] == 0)
            mp.erase(a[i]);
        if (mp.count(b[i]) && mp[b[i]] == 0)
            mp.erase(b[i]);
        if (mp.size() == 0)
            ans++;
    }
    cout << ans;

    return 0;
}