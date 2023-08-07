#include <bits/stdc++.h>
using namespace std;
#define lol long long
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol t;
    cin >> t;
    while (t--)
    {
        lol x, d;
        cin >> x >> d;
        lol c = 0;
        while (x % d == 0)
        {
            x /= d;
            c++;
        }
        vector<lol> p;
        for (lol i = 2; i * 1ll * i <= x; i++)
        {
            while (x % i == 0)
            {
                x /= i;
                p.push_back(i);
            }
        }
        if (x > 1)
            p.push_back(x);
        if (c > 1 && p.size() > 1)
        {
            cout << "YES\n";
        }
        else
        {
            c--;
            if (c <= 1)
            {
                cout << "NO\n";
                continue;
            }
            vector<lol> w;
            map<lol, lol> re;
            for (lol i = 2; i * 1ll * i <= d; i++)
            {
                while (d % i == 0)
                {
                    d /= i;
                    w.push_back(i);
                    re[i]++;
                }
            }
            if (d > 1)
            {
                w.push_back(d);
                re[d]++;
            }
            map<lol, lol> f;
            for (auto e : p)
                f[e]++;
            for (auto e : w)
                f[e]++;
            bool ans = false;
            if (re.size() > 1)
            {
                for (auto e : f)
                {
                    if (re[e.first] > e.second / c)
                        ans = true;
                }
            }
            else
            {
                for (auto e : f)
                {
                    if (re[e.first] > e.second / c + (e.second % c > 0))
                        ans = true;
                }
            }
            if (ans)
                cout << "YES\n";
            else
                cout << "NO\n";
        }
    }
}