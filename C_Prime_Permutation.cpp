#include <bits/stdc++.h>
#define lol long long
using namespace std;
map<lol, vector<lol>> mp;
lol dfs(lol c, bool vis[])
{
    vis[c] = true;
    lol q = 1;
    for (auto e : mp[c])
    {
        if (!vis[e])
        {
            q += dfs(e, vis);
        }
    }
    return q;
}
string s;
void dfs1(lol c, bool vis[], char q)
{
    vis[c] = true;
    s[c - 1] = q;
    for (auto e : mp[c])
    {
        if (!vis[e])
        {
            dfs1(e, vis, q);
        }
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> s;
    bool p[s.size() + 1];
    memset(p, true, sizeof(p));
    vector<lol> pri;
    for (lol i = 2; i <= s.size(); i++)
    {
        if (p[i])
        {
            pri.push_back(i);
            for (lol j = i * 1ll * i; j <= s.size(); j += i)
            {
                p[j] = false;
            }
        }
    }
    bool vis[s.size() + 1];
    memset(vis, false, sizeof(vis));
    for (auto e : pri)
    {

        for (lol i = 2 * 1ll * e; i <= s.size(); i += e)
        {
            mp[e].push_back(i);
            mp[i].push_back(e);
        }
    }
    vector<lol> co;
    for (lol i = 1; i <= s.size(); i++)
    {
        if (!vis[i])
        {
            co.push_back(dfs(i, vis));
        }
    }

    map<char, lol> cmp;
    for (auto c : s)
    {
        cmp[c]++;
    }

    map<lol, vector<char>> wow;
    for (auto e : cmp)
    {
        wow[e.second].push_back(e.first);
    }

    memset(vis, false, sizeof(vis));
    lol j = 0;
    lol i;
    for (i = 1; i <= s.size(); i++)
    {
        if (!vis[i])
        {
            if (wow.lower_bound(co[j]) != wow.end())
            {
                auto q = wow.lower_bound(co[j]);
                dfs1(i, vis, (*q).second.back());
                if ((*q).first > co[j])
                {
                    lol ne = (*q).first - co[j];
                    wow[ne].push_back((*q).second.back());
                }
                (*q).second.pop_back();
                if ((*q).second.size() == 0)
                {
                    wow.erase(q);
                }

                j++;
            }
            else
            {

                break;
            }
        }
    }
    if (i <= s.size())
    {
        cout << "NO";
    }
    else
    {
        cout << "YES" << endl;
        cout << s;
    }

    return 0;
}