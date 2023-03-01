#include <bits/stdc++.h>
#define lol long long
using namespace std;
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
        lol a[n + 1];
        memset(a, 0, sizeof(a));
        for (lol i = 0; i < n; i++)
        {
            lol q;
            cin >> q;
            a[q]++;
        }

        lol st = 0, e = n;
        while (st != e - 1)
        {
            lol m = (st + e) / 2;
            if (m == 0)
            {
                st = m;
            }
            else if (m == n)
            {
                e = m;
            }
            else
            {
                lol b[n];
                memset(b, -1, sizeof(b));
                set<pair<lol, lol>> x;
                for (lol i = 0; i <= n; i++)
                {
                    if (a[i] > 0)
                        x.insert({-a[i], i});
                }
                lol i = 0;
                queue<pair<lol, lol>> q;
                while (i < n)
                {
                    if (x.empty())
                        break;
                    pair<lol, lol> a = (*x.begin());
                    x.erase(x.begin());
                    if (a.first < 0)
                        b[i] = a.second;
                    a.first++;
                    q.push(a);
                    i++;
                    if (q.size() > m)
                    {
                        x.insert(q.front());
                        q.pop();
                    }
                }
                for (i = 0; i < n; i++)
                {
                    if (b[i] == -1)
                        break;
                }

                if (i == n)
                    st = m;
                else
                    e = m;
            }
        }
        cout << st << '\n';
    }

    return 0;
}