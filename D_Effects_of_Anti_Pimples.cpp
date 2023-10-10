#include <bits/stdc++.h>
using namespace std;
#define lol long long
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n;
    cin >> n;
    lol a[n];
    lol m = 998244353;
    lol pw[n + 2];
    pw[0] = 1;
    for (lol i = 1; i < n + 2; i++)
    {
        pw[i] = (pw[i - 1] * 2ll) % m;
    }
    map<lol, vector<lol>> mp;
    for (lol i = 0; i < n; i++)
    {
        cin >> a[i];
        mp[-a[i]].push_back(i + 1);
    }
    set<lol> exclude;
    lol ans = 0;
    for (auto e : mp)
    {
        set<lol> select;
        for (auto ee : e.second)
        {
            for (lol i = 1; i * 1ll * i <= ee; i++)
            {
                if (ee % i == 0)
                {
                    if (!exclude.count(i))
                    {

                        select.insert(i);
                    }
                    if ((ee / i) != i)
                    {
                        if (!exclude.count(ee / i))
                        {

                            select.insert(ee / i);
                        }
                    }
                }
            }
        }

        ans += ((((((pw[select.size()] - 1) % m + m) % m) * 1ll * (pw[n - select.size() - exclude.size()])) % m) * 1ll * (-e.first)) % m;
        ans %= m;
        for (auto ee : select)
            exclude.insert(ee);
        
    }
    cout << ans;
}