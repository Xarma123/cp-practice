#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol t;
    cin >> t;
    while (t--)
    {
        lol n, k;
        cin >> n >> k;
        pair<lol, lol> a[n];
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i].first;
            a[i].second = i;
        }
        sort(a, a + n);
        stack<pair<lol, lol>> c[k];
        lol sz = 1;
        lol j = 0;
        for (lol i = 0; i < n; i++)
        {
            bool f = false;
            lol q = 0;
            while (q < k)
            {
                if (c[j].size() < sz)
                {
                    f = true;
                    if (!c[j].empty())
                    {
                        if (c[j].top().first != a[i].first)
                        {
                            c[j].push(a[i]);
                            break;
                        }
                    }
                    else
                    {
                        c[j].push(a[i]);
                        break;
                    }
                }
                q++;
                j = (j + 1) % k;
            }
            if (!f)
            {
                sz++;
                i--;
            }
        }
        lol mnsz = INT_MAX;
        for (lol i = 0; i < k; i++)
        {
            mnsz = min(mnsz, (long long)c[i].size());
        }
        for (lol i = 0; i < k; i++)
        {
            while (c[i].size() > mnsz)
            {
                c[i].pop();
            }
        }
        for (lol i = 0; i < k; i++)
        {
            while (!c[i].empty())
            {
                a[c[i].top().second].first = -i - 1;
                c[i].pop();
            }
        }
        for (lol i = 0; i < n; i++)
        {
            if (a[i].first < 0)
                cout << -(a[i].first) << " ";
            else
                cout << 0 << " ";
        }
        cout << endl;
    }

    return 0;
}