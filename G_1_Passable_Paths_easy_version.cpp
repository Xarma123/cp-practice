#include <bits/stdc++.h>
#define lol long long
using namespace std;
map<lol, vector<lol>> mp;
bool x[200005];
bool q[200005];
bool ans;
void dfs(lol c, lol p)
{
    if (x[c])
        q[c] = true;
    for (auto e : mp[c])
    {
        if (e != p)
        {
            dfs(e, c);
            if (q[e] == true)
                q[c] = true;
        }
    }
}
void dfs1(lol c, lol p, bool upar)
{
    lol co = upar;
    vector<bool> pr, s;
    for (auto e : mp[c])
    {
        if (e != p)
        {
            if (q[e])
                co++;
            pr.push_back(q[e]);
            s.push_back(q[e]);
        }
    }
    if (co > 2)
        ans = false;
    for (lol i = 1; i < pr.size(); i++)
    {
        pr[i] = (pr[i] | pr[i - 1]);
    }
    for (lol i = (long long)s.size() - 2; i >= 0; i--)
    {
        s[i] = (s[i] | s[i + 1]);
    }
    lol i = 0;
    for (auto e : mp[c])
    {
        if (e != p)
        {
            bool nu = upar;
            if (x[c])
                nu = true;
            if (i)
                nu |= pr[i - 1];
            if (i < (long long)pr.size() - 1)
                nu |= s[i + 1];
            dfs1(e, c, nu);
            i++;
        }
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n;
    cin >> n;
    for (lol i = 0; i < n - 1; i++)
    {
        lol a, b;
        cin >> a >> b;
        mp[a].push_back(b);
        mp[b].push_back(a);
    }
    lol qq;
    cin >> qq;
    while (qq--)
    {
        ans = true;
   
        memset(q, false, sizeof(q));
        memset(x, false, sizeof(x));
        lol k;
        cin >> k;
        while (k--)
        {
            lol v;
            cin >> v;
            x[v] = true;
        }
        dfs(1, -1);
        dfs1(1, -1, false);
        if (ans)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}