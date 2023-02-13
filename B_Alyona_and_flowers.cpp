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
    lol ans = 0;
    while (m--)
    {
        lol l, r;
        cin >> l >> r;
        l--;
        lol s = 0;
        for (lol i = l; i < r; i++)
        {
            s += a[i];
        }
        if (s >= 0)
            ans += s;
    }
    cout << ans;

    return 0;
}