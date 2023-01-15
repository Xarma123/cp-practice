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
    map<lol, lol> mp;
    for (lol i = 0; i < n; i++)
    {
        lol q;
        cin >> q;
        mp[q]++;
    }
    lol m;
    cin >> m;
    lol b[m], c[m];
    pair<lol, lol> a[m];
    for (lol i = 0; i < m; i++)
    {
        cin >> b[i];
        a[i].first = mp[b[i]];
        a[i].second = i;
    }
    sort(a, a + m);
    for (lol i = 0; i < m; i++)
    {
        cin >> c[i];
    }
    lol j = m - 1;
    lol ans = a[m - 1].second;
    lol t = mp[c[a[m - 1].second]];
    while (j >= 0 && a[j].first == a[m - 1].first)
    {
        if (t < mp[c[a[j].second]])
        {
            t = mp[c[a[j].second]];
            ans = a[j].second;
        }
        j--;
    }
    cout << ans + 1;

    return 0;
}