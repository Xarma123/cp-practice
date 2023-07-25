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
        lol a[n];
        map<lol, vector<lol>> mp;
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
            mp[a[i]].push_back(i);
        }
        deque<pair<lol, vector<lol>>> v;
        for (auto e : mp)
        {
            v.push_back(e);
        }
        lol p = 0, ne = 0;
        bool ans = true;
        lol f[n];
        lol q = n;
        while (!v.empty())
        {
            if (v.back().first == n - ne && v[0].first == p && n - ne != p)
            {
                ans = false;
                break;
            }
            else if (v[0].first == p)
            {
                for (auto e : v[0].second)
                    f[e] = -q;
                ne += v[0].second.size();
                v.pop_front();
            }
            else if (v.back().first == n - ne)
            {
                for (auto e : v.back().second)
                    f[e] = q;
                p += v.back().second.size();
                v.pop_back();
            }
            else
            {
                ans = false;
                break;
            }
            q--;
        }
        if (ans)
        {
            cout << "YES\n";
            for (lol i = 0; i < n; i++)
            {
                cout << f[i] << " ";
            }
            cout << '\n';
        }
        else
            cout << "NO\n";
    }
}