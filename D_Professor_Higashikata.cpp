#include <bits/stdc++.h>
using namespace std;
#define lol long long

int main()
{
    lol n, m, q;
    cin >> n >> m >> q;
    string s;
    cin >> s;

    set<lol> x;
    for (lol i = 0; i < s.size(); i++)
    {
        x.insert(i);
    }
    lol totone = 0;
    for (auto e : s)
    {
        if (e == '1')
            totone++;
    }
    vector<lol> order;
    map<lol, lol> d;
    for (lol i = 0; i < m; i++)
    {
        lol a, b;
        cin >> a >> b;
        a--;
        b--;

        while ((!x.empty()) && x.lower_bound(a) != x.end() && (*x.lower_bound(a)) <= b)
        {
            lol in = (*x.lower_bound(a));
            order.push_back(in);
            d[in] = (long long)order.size() - 1;
            x.erase(in);
        }
    }
    lol ans = 0;
    for (lol i = 0; i < totone && i < order.size(); i++)
    {
        ans += 1 - (s[order[i]] - '0');
    }

    while (q--)
    {
        lol i;
        cin >> i;
        i--;
        if (d.count(i))
        {
            lol olr = min(totone, (long long)order.size()) - 1;
            if (s[i] == '0')
            {
                totone++;
            }
            else
            {
                totone--;
            }
            lol nr = min(totone, (long long)order.size()) - 1;
            if (olr < nr)
            {
                if (nr >= 0 && s[order[nr]] == '0')
                    ans++;
            }
            else if (olr > nr)
            {
                if (olr >= 0 && s[order[olr]] == '0')
                    ans--;
            }
            if (s[i] == '0')
            {
                if (d[i] <= nr)
                    ans--;
                s[i] = '1';
            }
            else
            {
                if (d[i] <= nr)
                {
                    ans++;
                }
                s[i] = '0';
            }
        }
        else
        {
            lol olr = min(totone, (long long)order.size()) - 1;
            if (s[i] == '1')
            {
                s[i] = '0';
                totone--;
            }
            else
            {
                s[i] = '1';
                totone++;
            }
            lol nr = min(totone, (long long)order.size()) - 1;
            if (olr < nr)
            {
                if (nr >= 0 && s[order[nr]] == '0')
                    ans++;
            }
            else if (olr > nr)
            {
                if (olr >= 0 && s[order[olr]] == '0')
                    ans--;
            }
        }
        cout << ans << '\n';
    }
}