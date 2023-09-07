#include <bits/stdc++.h>
using namespace std;
#define lol long long
map<lol, lol> ev;
lol solve(lol n)
{
    lol p10 = 1;

    for (lol i = 0; i < n; i++)
    {
        p10 = p10 * 10ll;
    }
    return (p10 * 1ll * n - ((p10 - 1) / 9ll));
}
lol solve2(string a)
{
    string q = "1";
    lol c = a.size() - 1;
    while (c--)
    {
        q += '0';
    }
    return (long long)a.size() * 1ll * (stoll(a) - stoll(q) + 1);
}
lol eval1(lol a)
{
    if (a == 0)
        return 0;
    if (ev.count(a))
        return ev[a];
    lol co = 0;
    string s = to_string(a);
    co = solve(s.size() - 1);
    co += solve2(s);
    return ev[a] = co;
}

lol eval(lol a)
{

    if (a == 0)
        return 0;
    if (a == 1)
        return 1;
    if (ev.count(a))
    {

        return ev[a];
    }
    // cout << a << endl;
    string s = to_string(a);
    return ev[a] = ((long long)s.size() + (eval(a - 1) - eval(a - 2)) + eval(a - 1));
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol q;
    cin >> q;
    while (q--)
    {
        lol k;
        cin >> k;
        if (k == 1)
        {
            cout << 1 << endl;
            continue;
        }
        lol c = 1;
        lol tot = 1;

        lol s = 1, e = 2ll * ceill(sqrtl(k));
        while (s != e - 1)
        {
            lol m = (s + e) / 2;
            
            if (eval(m) < k)
            {
                s = m;
            }
            else
                e = m;
        }
        c = s;
        tot = eval(s);

        s = 0;
        e = c + 1;
        while (s != e - 1)
        {
            lol m = (s + e) / 2;
            if (m == 0)
            {
                s = m;
            }
            else if (eval(m) - eval(m - 1) >= k - tot)
            {
                e = m;
            }
            else
                s = m;
        }

        if (s != 0)
            tot += eval(s) - eval(s - 1);

        k -= tot;
        string qq = to_string(e);

        cout << qq[k - 1] << endl;
    }
}