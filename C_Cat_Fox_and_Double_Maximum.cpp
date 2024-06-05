#include <bits/stdc++.h>
using namespace std;
#define lol long long
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol t;
    cin >> t;
    while (t--)
    {
        lol n;
        cin >> n;
        lol a[n];
        set<lol> x;
        lol f = -1;
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
            x.insert(i + 1);
            if (a[i] == 1)
            {
                if (i % 2)
                {
                    f = 1;
                }
                else
                {
                    f = 0;
                }
            }
        }
        lol ans[n];
        memset(ans, -1, sizeof(ans));
        for (lol i = 1; i < n - 1; i++)
        {
            if (f != (i % 2))
            {
                ans[i] = (n + 2) - a[i];
                x.erase(ans[i]);
            }
        }
        for (lol i = 0; i < n; i++)
        {
            if (ans[i] == -1)
            {
                auto it = x.upper_bound(n + 1 - a[i]);
                it--;
                ans[i] = (*it);
                x.erase(it);
            }
            cout << ans[i] << " ";
        }
        cout << '\n';
    }

    return 0;
}
