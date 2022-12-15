#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n, t, c;
    cin >> n >> t >> c;
    lol a[n];
    for (lol i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    map<lol, lol> f;
    lol ans = 0;
    for (lol i = 0; i < c; i++)
    {
        f[a[i]]++;
    }
    if ((*f.rbegin()).first <= t)
        ans++;
    for (lol i = c; i < n; i++)
    {
        f[a[i - c]]--;
        if (f[a[i - c]] == 0)
            f.erase(a[i - c]);
        f[a[i]]++;
        if ((*f.rbegin()).first <= t)
            ans++;
    }
    cout << ans;

    return 0;
}