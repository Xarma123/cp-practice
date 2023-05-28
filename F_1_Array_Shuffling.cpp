#include <bits/stdc++.h>
#define lol long long
using namespace std;
bool cmp(pair<lol, vector<lol>> a, pair<lol, vector<lol>> b)
{
    return a.second.size() > b.second.size();
}
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
        lol a[n];
        map<lol, vector<lol>> m;
        lol f = 0, mx;
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i], m[a[i]].push_back(i);
            if (f < m[a[i]].size())
            {
                f = m[a[i]].size();
                mx = a[i];
            }
        }
        vector<lol> init;
        for (auto e : m)
        {
            if (e.first == mx)
                continue;
            for (auto f : e.second)
                init.push_back(f);
        }
        lol i = init.size();
        for (auto f : m[mx])
            init.push_back(f);
        lol b[n];
        for (auto e : init)
        {
            b[e] = a[init[i]];
            i++;
            i %= (long long)init.size();
        }
        for (lol i = 0; i < n; i++)
        {
            cout << b[i] << " ";
        }
        cout << '\n';
    }

    return 0;
}