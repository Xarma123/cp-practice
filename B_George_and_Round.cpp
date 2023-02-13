#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n, m;
    cin >> n >> m;
    lol a[n];
    for (lol i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a, a + n);
    multiset<lol> x;
    while (m--)
    {
        lol v;
        cin >> v;
        x.insert(v);
    }
    lol ans = 0;
    for (lol i = n - 1; i >= 0; i--)
    {
        auto it = x.lower_bound(a[i]);
        if (it == x.end())
            ans++;
        else
            x.erase(it);
    }
    cout << ans;

    return 0;
}