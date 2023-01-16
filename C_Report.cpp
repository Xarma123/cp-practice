#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n, m;
    cin >> n >> m;
    lol a[n];
    for (lol i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    pair<lol, lol> o[m];
    pair<lol, lol> q[m];
    for (lol i = 0; i < m; i++)
    {
        cin >> o[i].first >> o[i].second;
        q[i].first = o[i].second;
        q[i].second = i;
    }
    sort(q, q + m);
    vector<lol> al;
    for (lol j = m - 1; j >= 0; j--)
    {
        lol jj = j - 1;
        lol ind = q[j].second;
        while (jj >= 0 && q[jj].first == q[j].first)
        {
            ind = max(ind, q[jj].second);
            jj--;
        }
        j = jj + 1;
        if (al.size() == 0)
            al.push_back(ind);
        else if (al.back() < ind)
        {
            al.push_back(ind);
        }
    }
    lol i = 0;
    map<lol, lol> mp;
    for (lol j = 0; j < o[al[i]].second; j++)
    {
        mp[a[j]]++;
    }
    bool f;
    lol j = o[al[i]].second - 1;
    for (; j >= 0; j--)
    {
        if (i < al.size())
        {
            if (o[al[i]].second - 1 == j)
            {
                if (o[al[i]].first == 1)
                    f = true;
                else
                    f = false;
                i++;
            }
        }
        if (f)
        {
            lol v = (*mp.rbegin()).first;
            mp[v]--;
            if (mp[v] == 0)
                mp.erase(v);
            a[j] = v;
        }
        else
        {
            lol v = (*mp.begin()).first;
            mp[v]--;
            if (mp[v] == 0)
                mp.erase(v);
            a[j] = v;
        }
    }
    for (i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }

    return 0;
}