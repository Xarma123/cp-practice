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

        lol mx = 0;
        for (lol i = 1; i < n; i++)
        {
            if (a[i].first >= a[0].first)
            {
                mx = max(mx, a[i].second);
            }
        }
        if (mx < a[0].second)
        {
            cout << a[0].first << '\n';
        }
        else
            cout << -1 << '\n'; 
    }
}