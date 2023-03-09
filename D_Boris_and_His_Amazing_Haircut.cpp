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
        lol a[n];
        lol b[n];
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (lol i = 0; i < n; i++)
        {
            cin >> b[i];
        }
        map<lol, lol> razor;
        lol m;
        cin >> m;
        while (m--)
        {
            lol v;
            cin >> v;
            razor[v]++;
        }
        lol nx[n];
        stack<lol> s;
        s.push(-1);
        for (lol i = 0; i < n; i++)
        {
            while (s.top() != -1 && b[s.top()] < b[i])
            {
                nx[s.top()] = i;
                s.pop();
            }
            s.push(i);
        }
        while (s.top() != -1 && !s.empty())
        {
            nx[s.top()] = n;
            s.pop();
        }
        bool ans = true;
        map<lol, vector<lol>> mp;
        for (lol i = 0; i < n; i++)
        {
            if (b[i] > a[i])
            {
                ans = false;
            }
            else if (b[i] < a[i])
            {
                mp[b[i]].push_back(i);
            }
        }
        for (auto e : mp)
        {
            lol l = 0;
            lol c = 0;
            for (auto f : e.second)
            {
                if (f < l)
                    continue;
                c++;
                l = nx[f];
            }
            if (razor[e.first] < c)
                ans = false;
        }
        if (ans)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}