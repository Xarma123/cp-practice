#include <bits/stdc++.h>
#define lol long long
using namespace std;
bool cmp(lol a, lol b)
{
    return a > b;
}
int main()
{
    lol n, k;
    cin >> n >> k;
    string a;
    cin >> a;
    vector<lol> mp;
    for (lol i = 0; i < 26; i++)
    {
        mp.push_back(0);
    }

    for (lol i = 0; i < n; i++)
    {
        mp[a[i] - 'A']++;
    }
    sort(mp.begin(), mp.end(), cmp);

    lol ans = 0;
    for (lol i = 0; i < 26; i++)
    {
        if (mp[i] <= k)
        {
            k -= mp[i];
            ans += mp[i] * mp[i];
        }
        else
        {
            ans += k * k;
            k = 0;
        }
        if (k == 0)
            break;
    }
    cout << ans;

    return 0;
}