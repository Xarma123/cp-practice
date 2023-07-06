#include <bits/stdc++.h>
using namespace std;
#define lol long long
bool cmp(pair<lol, lol> a, pair<lol, lol> b)
{
    if (a.first > b.first)
        return true;
    return false;
}
int main()
{
    lol n, v;
    cin >> n >> v;
    vector<pair<lol, lol>> o, s;
    for (lol i = 0; i < n; i++)
    {
        lol p, c;
        cin >> p >> c;
        if (p == 1)
        {
            o.push_back({c, i});
        }
        else
        {
            s.push_back({c, i});
        }
    }
    sort(o.begin(), o.end(), cmp);
    sort(s.begin(), s.end(), cmp);
    for (lol i = 1; i < o.size(); i++)
    {
        o[i].first += o[i - 1].first;
    }
    for (lol i = 1; i < s.size(); i++)
    {
        s[i].first += s[i - 1].first;
    }
    lol ans = LONG_LONG_MIN;
    lol ii;
    for (lol i = 0; i <= n && i <= v; i++)
    {
        lol j = (v - i) / 2;
        lol c = 0;
        if (i > 0 && o.size())
            c += o[min(i, (long long)o.size()) - 1].first;
        if (j > 0)
            c += s[min(j, (long long)s.size()) - 1].first;
        if (ans < c && s.size())
        {
            ii = i;
        }
        ans = max(ans, c);
    }
    cout << ans << '\n';
    for (lol i = 0; i < ii && i < o.size(); i++)
    {
        cout << o[i].second + 1 << " ";
    }
    ii = (v - ii) / 2;
    for (lol i = 0; i < ii && i < s.size(); i++)
    {
        cout << s[i].second + 1 << " ";
    }
}