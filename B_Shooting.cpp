#include <bits/stdc++.h>
using namespace std;
#define lol long long
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n;
    cin >> n;
    pair<lol, lol> a[n];
    for (lol i = 0; i < n; i++)
    {
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a, a + n);
    lol ans = n;
    for (lol i = 0; i < n; i++)
    {
        ans += a[i].first * 1ll * (n - 1 - i);
    }
    cout << ans << '\n';
    for (lol i = n - 1; i >= 0; i--)
    {
        cout << a[i].second + 1 << " ";
    }
}