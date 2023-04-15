#include <bits/stdc++.h>
#define lol long long
using namespace std;
vector<pair<lol, lol>> we;
bool cmp(lol a, lol b)
{
    if (we[a].first < we[b].first)
    {
        return true;
    }
    else if (we[a].first == we[b].first)
    {
        return we[a].second < we[b].second;
    }
    return false;
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
        we.clear();

        cin >> n;
        lol b[n];
        for (lol i = 0; i < n; i++)
        {
            cin >> b[i];
            pair<lol, lol> a;
            lol st = 0, e = n + 1;
            while (st != e - 1)
            {
                lol m = (st + e) / 2;
                if (m == n + 1)
                    e = m;
                else if (m == 0)
                    st = m;
                else if (((i + 1) / m) <= b[i])
                    e = m;
                else
                    st = m;
            }
            a.second = e;
            st = 0, e = n + 1;
            while (st != e - 1)
            {
                lol m = (st + e) / 2;
                if (m == n + 1)
                    e = m;
                else if (m == 0)
                    st = m;
                else if (((i + 1) / m) < b[i])
                    e = m;
                else
                    st = m;
            }
            a.first = e;
            we.push_back(a);
        }
        lol q[n];
        for (lol i = 0; i < n; i++)
        {
            q[i] = i;
        }
        sort(q, q + n, cmp);
        lol j = n - 1;
        set<pair<lol, lol>> m;
        lol ans[n];
        for (lol i = n; i >= 1; i--)
        {
            while (j >= 0 && we[q[j]].first > i)
            {
                m.insert({-we[q[j]].second, q[j]});
                j--;
            }
            ans[(*m.begin()).second] = i;
            m.erase(m.begin());
        }
        for (lol i = 0; i < n; i++)
        {
            cout << ans[i] << " ";
        }

        cout << '\n';
    }

    return 0;
}