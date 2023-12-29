#include <bits/stdc++.h>
using namespace std;
#define lol long long
lol sum(string &a)
{
    lol r = 0;
    for (auto e : a)
        r += (e - '0');
    return r;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n;
    cin >> n;
    string a[n];
    for (lol i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    map<lol, vector<string>> mp;
    for (lol i = 0; i < n; i++)
    {
        mp[(long long)a[i].size()].push_back(a[i]);
    }
    lol ans = 0;
    for (lol i = 1; i <= 5; i++)
    {
        for (lol j = 1; j <= 5; j++)
        {
            if ((i + j) % 2 != 0)
            {
                continue;
            }
            if (i == j)
                continue;
            if (i < j)
            {
                lol v = (i + j) / 2ll;
                v -= i;

                map<lol, lol> lf;
                for (auto e : mp[i])
                {

                    lf[sum(e)]++;
                }
                for (auto e : mp[j])
                {
                    lol val = 0;
                    for (lol k = 0; k < e.size(); k++)
                    {
                        if (k < v)
                            val -= (e[k] - '0');
                        else
                            val += (e[k] - '0');
                    }

                    ans += lf[val];
                }
            }
            else
            {
                lol v = (i + j) / 2ll;
                v -= j;
                map<lol, lol> rt;
                for (auto e : mp[j])
                {
                    rt[sum(e)]++;
                }
                for (auto e : mp[i])
                {
                    lol val = 0;
                    for (lol k = 0; k < e.size(); k++)
                    {
                        if (k < e.size() - v)
                            val += (e[k] - '0');
                        else
                            val -= (e[k] - '0');
                    }
                    ans += rt[val];
                }
            }
        }
    }
    map<lol, map<lol, lol>> mp1;
    for (lol i = 0; i < n; i++)
    {
        ans += 2ll * mp1[a[i].size()][sum(a[i])] + 1;
        mp1[a[i].size()][sum(a[i])]++;
    }
    cout << ans;

    return 0;
}
