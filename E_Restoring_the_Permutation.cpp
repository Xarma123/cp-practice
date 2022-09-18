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
        lol q[n];
        set<lol> x;
        set<lol> in;
        for (lol i = 0; i < n; i++)
        {
            x.insert((i + 1));
            cin >> q[i];
        }
        in.insert(0);
        x.erase(q[0]);

        for (lol i = 1; i < n; i++)
        {
            if (q[i] > q[i - 1])
            {
                in.insert(i);
                x.erase(q[i]);
            }
        }

        auto d = x.begin();
        for (lol i = 0; i < n; i++)
        {
            if (!in.count(i))
            {
                q[i] = (*d);
                d++;
            }
        }
        for (lol i = 0; i < n; i++)
        {
            cout << q[i] << " ";
        }
        cout << endl;

        in.erase(0);
        lol u = 0;
        for (lol i = 1; i < n; i++)
        {
            if (i == (*in.begin()))
            {
                u = i;
                in.erase(i);
                continue;
            }
            auto d = x.lower_bound(q[u]);
            if (d == x.end())
            {
                lol g = (*x.rbegin());
                d = x.find(g);
            }
            else
            {
                while ((*d) >= q[u])
                {
                    d--;
                }
            }

            q[i] = (*d);
            x.erase(d);
        }
        for (lol i = 0; i < n; i++)
        {
            cout << q[i] << " ";
        }
        cout << endl;
    }

    return 0;
}