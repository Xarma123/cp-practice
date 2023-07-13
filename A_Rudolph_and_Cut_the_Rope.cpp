#include <bits/stdc++.h>
using namespace std;
#define lol long long
int main()
{
    lol t;
    cin >> t;
    while (t--)
    {
        lol n;
        cin >> n;
        pair<lol, lol> a[n];
        lol ans = n;
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i].first >> a[i].second;
            if (a[i].second >= a[i].first)
                ans--;
        }
        cout << ans << '\n';
    }
}