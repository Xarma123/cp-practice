#include <bits/stdc++.h>
using namespace std;
#define lol long long
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
        pair<lol, lol> a[n];
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i].first >> a[i].second;
        }
        sort(a, a + n);
        lol mn = LONG_LONG_MAX;
        for (lol i = 0; i < n; i++)
        {
            if (a[i].first >= mn)
                break;
            mn = min(mn, a[i].first + (a[i].second / 2) - (a[i].second % 2 == 0));
        }
        cout << mn << '\n';
    }
}