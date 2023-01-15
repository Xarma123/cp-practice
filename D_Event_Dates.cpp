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
    pair<lol, pair<lol, lol>> a[n];
    lol l = LONG_LONG_MIN;
    for (lol i = 0; i < n; i++)
    {
        cin >> a[i].second.first >> a[i].first;
        a[i].second.second = i;
    }
    sort(a, a + n);
    lol ans[n];
    set<lol> us;
    for (lol i = 0; i < n; i++)
    {
        lol j = a[i].second.first;
        while (us.count(j))
            j++;
        ans[a[i].second.second] = j;
        us.insert(j);
    }
    for (lol i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}