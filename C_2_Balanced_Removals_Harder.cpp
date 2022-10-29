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
    vector<pair<lol, pair<lol, pair<lol, lol>>>> p;
    map<pair<lol, lol>, vector<pair<lol, lol>>> mp;
    for (lol i = 0; i < n; i++)
    {
        lol x, y, z;
        cin >> x >> y >> z;
        p.push_back({x, {y, {z, i}}});
        mp[{x, y}].push_back({z, i});
    }
    sort(p.begin(), p.end());
    bool used[n];
    for (lol i = 0; i < n; i++)
    {
        used[i] = false;
    }

    for (auto e : mp)
    {
        vector<pair<lol, lol>> v = e.second;
        sort(v.begin(), v.end());
        for (lol i = 1; i < v.size(); i += 2)
        {
            cout << v[i].second + 1 << " " << v[i - 1].second + 1 << endl;
            used[v[i].second] = true;
            used[v[i - 1].second] = true;
        }
    }
    for (lol i = 0; i < n; i++)
    {
        lol j = i + 1;
        while (j < n && p[j].first == p[i].first)
            j++;
        vector<lol> ind;
        for (lol k = i; k < j; k++)
        {
            if (!used[p[k].second.second.second])
            {
                ind.push_back(p[k].second.second.second);
            }
        }
        for (lol k = 1; k < ind.size(); k += 2)
        {
            used[ind[k]] = true;
            used[ind[k - 1]] = true;
            cout << ind[k] + 1 << " " << ind[k - 1] + 1 << endl;
        }
        i = j - 1;
    }
    vector<lol> newi;
    for (lol i = 0; i < n; i++)
    {
        if (!used[p[i].second.second.second])
        {
            newi.push_back(p[i].second.second.second);
        }
    }
    for (lol i = 1; i < newi.size(); i += 2)
    {
        cout << newi[i] + 1 << " " << newi[i - 1] + 1 << endl;
    }

    return 0;
}