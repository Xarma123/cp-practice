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
        lol n, m;
        cin >> n >> m;
        deque<lol> a[n];
        for (lol i = 0; i < n; i++)
        {
            vector<lol> v;
            for (lol j = 0; j < m; j++)
            {
                lol c;
                cin >> c;
                v.push_back(c);
            }
            sort(v.begin(), v.end());
            while (v.size())
            {
                a[i].push_back(v.back());
                v.pop_back();
            }
        }
        vector<lol> ans[n];
        for (lol j = 0; j < m; j++)
        {
            lol mn = 0;
            for (lol i = 0; i < n; i++)
            {
                if (a[i].back() < a[mn].back())
                {
                    mn = i;
                }
            }
            for (lol i = 0; i < n; i++)
            {
                if (i == mn)
                {
                    ans[i].push_back(a[i].back());
                    a[i].pop_back();
                }
                else
                {
                    ans[i].push_back(a[i].front());
                    a[i].pop_front();
                }
            }
        }
        for (lol i = 0; i < n; i++)
        {
            for (auto e : ans[i])
                cout << e << " ";
            cout << '\n';
        }
    }
}