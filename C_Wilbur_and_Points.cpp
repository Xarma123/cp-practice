#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n;
    cin >> n;
    vector<pair<lol, lol>> v(n);
    for (lol i = 0; i < n; i++)
    {
        cin >> v[i].first >> v[i].second;
    }
    sort(v.begin(), v.end(), cmp);
    lol w[n];
    for (lol i = 0; i < n; i++)
    {
        cin >> w[i];
    }
    for (lol i = 0; i < n; i++)
    {
        cout << v[i].first << " " << v[i].second << endl;
    }
    lol i;
    for (i = 0; i < n; i++)
    {
        map<lol, set<lol>> mp;
        mp[v[i].second - v[i].first].insert(i);
        lol j = i + 1;
        while (j < n && chk(v[i], v[j]))
        {
            mp[v[j].second - v[j].first].insert(j);
            j++;
        }       
        cout << i << " " << j << endl;
        for (auto e : mp)
        {
            cout << e.first << endl;
            for (auto c : e.second)
                cout << c << " ";
            cout << endl;
            cout << endl;
        }
        while (i < j)
        {
            if (mp[w[i]].size() == 0)
            {
                break;
            }
            lol q = v[i].second - v[i].first;
            lol q2 = (*mp[w[i]].begin());
            swap(v[i], v[q2]);
            mp[w[i]].erase(q2);
            mp[q].erase(i);
            mp[q].insert(q2);
            i++;
        }
        if (i != j)
            break;
        i--;
    }

    if (i == n)
    {
        cout << "YES" << endl;
        for (auto e : v)
            cout << e.first << " " << e.second << endl;
    }
    else
        cout << "NO";

    return 0;
}