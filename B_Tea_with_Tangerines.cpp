#include <bits/stdc++.h>
#define lol long long
using namespace std;
lol solve(lol a, lol mn)
{
    if (a < mn)
        return 0;
    return (a / (mn-1))+((a%(mn-1))>0)-1;
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol t;
    cin >> t;
    while (t--)
    {
        lol n;
        cin >> n;
        lol a[n];
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        sort(a, a + n);
        lol v = a[0] * 1ll * 2;
        lol ans = 0;
        for (lol i = 1; i < n; i++)
        {
            ans += solve(a[i], v);
        }
        cout << ans << endl;
    }

    return 0;
}