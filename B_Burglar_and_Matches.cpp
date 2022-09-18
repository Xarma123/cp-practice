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
    pair<lol, lol> x[m];
    for (lol i = 0; i < m; i++)
    {
        cin >> x[i].first >> x[i].second;
        swap(x[i].first, x[i].second);
    }
    sort(x, x + m);
    lol ans = 0;
    for (lol i = m - 1; i >= 0; i--)
    {
        if (n >= x[i].second)
        {
            n -= x[i].second;
            ans += x[i].first * x[i].second;
        }
        else
        {
            ans += x[i].first * n;
            n = 0;
        }
    }
    cout << ans;

    return 0;
}