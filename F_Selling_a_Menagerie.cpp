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
        lol a[n], b[n];
        lol ind[n];
        for (lol i = 0; i < n; i++)
        {
            ind[i] = 0;
        }
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
            a[i]--;
            ind[a[i]]++;
        }
        for (lol i = 0; i < n; i++)
        {
            cin >> b[i];
        }
        set<pair<lol, lol>> x;
        for (lol i = 0; i < n; i++)
        {
            x.insert({ind[i], i});
        }
        while (!x.empty() && (*x.begin()).first == 0)
        {
            pair<lol, lol> top = (*x.begin());
            x.erase(x.begin());
            cout << top.second + 1 << ' ';
            if (x.count({ind[a[top.second]], a[top.second]}))
            {
                x.erase({ind[a[top.second]], a[top.second]});
                ind[a[top.second]]--;
                x.insert({ind[a[top.second]], a[top.second]});
            }
        }

        for (lol i = 0; i < n; i++)
        {
            vector<lol> v;
            if (ind[i])
            {
                v.push_back(i);
                lol j = a[i];
                ind[i] = 0;
                lol mn = b[i];
                while (ind[j] != 0)
                {
                    v.push_back(j);
                    mn = min(mn, b[j]);
                    ind[j] = 0;
                    j = a[j];
                }
                bool p = false;

                for (lol k = 0; k < v.size(); k++)
                {
                    if (p)
                    {
                        cout << v[k] + 1 << " ";
                    }
                    else if (b[v[k]] == mn)
                    {
                        p = true;
                        j = k;
                    }
                }
                for (lol k = 0; k <= j; k++)
                    cout << v[k] + 1 << ' ';
            }
        }

        cout << '\n';
    }
}