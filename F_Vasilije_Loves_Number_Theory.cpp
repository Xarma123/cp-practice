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
        lol n, q;
        cin >> n >> q;
        lol N = n;
        map<lol, lol> f, f2;
        for (lol i = 2; i * 1ll * i <= N; i++)
        {
            while (N % i == 0)
            {
                f[i]++;
                f2[i] = f[i];
                N /= i;
            }
        }
        if (N > 1)
        {
            f[N]++;
            f2[N]++;
        }
        N = n;
        while (q--)
        {
            lol k;
            cin >> k;
            if (k == 2ll)
            {
                f.clear();
                for (auto e : f2)
                    f[e.first] = e.second;
            }
            else
            {
                lol x;
                cin >> x;

                for (lol i = 2; i * 1ll * i <= x; i++)
                {
                    while (x % i == 0)
                    {
                        f[i]++;
                        x /= i;
                    }
                }
                if (x > 1)
                    f[x]++;
                lol tot = 1;
                lol val = 1;
                for (auto e : f)
                {
                    tot = tot * 1ll * (e.second + 1);
                }
                bool ans = true;
                for (lol i = 2; i * 1ll * i <= tot && ans; i++)
                {
                    lol c = 0;
                    while (tot % i == 0)
                    {
                        tot /= i;
                        c++;
                    }
                    if (c)
                    {
                        if (!(f.count(i) && f[i] >= c))
                            ans = false;
                    }
                }
                if (tot > 1)
                {
                    if (!(f.count(tot) && f[tot] >= 1))
                        ans = false;
                }
                if (ans)
                    cout << "YES\n";
                else
                    cout << "NO\n";
            }
        }
    }
}