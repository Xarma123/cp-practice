#include <bits/stdc++.h>
using namespace std;
#define lol long long
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n, q;
    cin >> n >> q;
    deque<lol> a(n);
    for (lol i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    vector<pair<lol, lol>> ans(n);
    for (lol i = 0; i < n; i++)
    {
        ans[i] = {a[0], a[1]};
        lol x = a[0];
        lol y = a[1];
        a.pop_front();
        a.pop_front();
        if (x < y)
        {
            a.push_back(x);
            a.push_front(y);
        }
        else
        {
            a.push_back(y);
            a.push_front(x);
        }
    }
    while (q--)
    {
        lol m;
        cin >> m;
        if (m <= n)
        {
            cout << ans[m - 1].first << " " << ans[m - 1].second << '\n';
        }
        else
        {
            m -= n;
            m %= (n - 1);
            if (m == 0)
            {
                cout << a[0] << " " << a[n - 1];
            }
            else
            {
                cout << a[0] << " " << a[m];
            }
            cout << '\n';
        }
    }
}