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
        map<lol, vector<lol>> mp;
        lol p[n];
        lol q[n];
        set<lol> pa, qa;
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
            mp[a[i]].push_back(i);
            pa.insert(i + 1);
            qa.insert(i + 1);
        }
        bool ans = true;
        for (auto e : mp)
        {
            for (auto c : e.second)
            {
                if (pa.count(e.first) && qa.size() > 0 && (*qa.begin()) <= e.first)
                {
                    p[c] = e.first;
                    pa.erase(e.first);
                    q[c] = (*qa.begin());
                    qa.erase(qa.begin());
                }
                else if (qa.count(e.first) && pa.size() > 0 && (*pa.begin()) <= e.first)
                {
                    q[c] = e.first;
                    qa.erase(e.first);
                    p[c] = (*pa.begin());
                    pa.erase(pa.begin());
                }
                else
                {
                    ans = false;
                    break;
                }
            }
            if (!ans)
                break;
        }
        if (ans)
        {
            cout << "YES" << endl;
            for (lol i = 0; i < n; i++)
            {
                cout << p[i] << " ";
            }
            cout << endl;
            for (lol i = 0; i < n; i++)
            {
                cout << q[i] << " ";
            }
            cout << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}