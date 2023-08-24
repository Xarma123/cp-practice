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
    pair<lol, lol> x[n];
    for (lol i = 0; i < n; i++)
    {
        cin >> x[i].first;
    }
    for (lol i = 0; i < n; i++)
    {
        cin >> x[i].second;
    }
    sort(x, x + n);
    lol ans = 0;
    lol s = 0;
    for (lol i = n - 1; i >= 0; i--)
    {
        ans += s - x[i].first * 1ll * (n - i - 1);
        s += x[i].first;
    }
    s = 0;
    lol c = 0;
    for (lol i = n - 1; i >= 0; i--)
    {
        if (x[i].second > 0)
            ans -= s - x[i].first * 1ll * c;
        else if (x[i].second < 0)
        {
            s += x[i].first;
            c++;
        }
    }
    cout << ans;
}