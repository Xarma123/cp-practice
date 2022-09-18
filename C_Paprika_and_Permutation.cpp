#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
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

        unordered_set<lol> x;
        for (lol i = 0; i < n; i++)
        {
            if (a[i] <= n)
            {
                if (!x.count(a[i]))
                {
                    x.insert(a[i]);
                    a[i] = 0;
                }
            }
        }
        if (x.size() == n)
            cout << 0 << endl;
        else
        {
            set<lol, greater<lol>> y;
            for (lol i = 1; i <= n; i++)
            {
                if (!x.count(i))
                {
                    y.insert(i);
                }
                else
                    x.erase(i);
            }
            sort(a, a + n);
            auto it = y.begin();
            lol ans = 0;
            lol i;
            for (i = n - 1; i >= 0; i--)
            {
                if (a[i] > 0)
                {

                    if ((*it) >= 1 && (long double)(*it) < (a[i] / 2.0))
                    {
                        ans++;
                        it++;
                    }
                }

                if (it == y.end())
                    break;
            }
            if (i < 0)
                cout << -1 << endl;
            else
                cout << ans << endl;
        }
    }

    return 0;
}