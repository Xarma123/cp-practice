#include <bits/stdc++.h>
#define lol long long
using namespace std;

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol t;
    cin >> t;
    while (t--)
    {
        lol n, k;
        string a, b;
        cin >> n >> k;
        cin >> a >> b;
        vector<char> x;
        set<char> y;
        for (auto e : a)
            y.insert(e);
        for (auto e : y)
            x.push_back(e);
        if (k >= x.size())
        {
            cout << n * 1ll * (n + 1) / 2 << '\n';
        }
        else
        {
            lol ans = 0;
            bool f[26];
            for (lol i = 0; i < (1ll << (x.size())); i++)
            {
                for (lol j = 0; j < 26; j++)
                    f[j] = false;
                set<char> ct;
                for (lol j = 0; j < x.size(); j++)
                {
                    if ((i & (1ll << j)) && ct.size() < k)
                    {
                        ct.insert(x[j]);
                    }
                }
                for (auto e : ct)
                {
                    f[e - 'a'] = true;
                }
                lol c = 0;
                for (lol k = 0; k < n; k++)
                {
                    if (a[k] == b[k] || f[a[k] - 'a'])
                    {
                        lol j = k + 1;
                        while (j < n && (a[j] == b[j] || f[a[j] - 'a']))
                            j++;
                        c += (j - k) * 1ll * (j - k + 1) / 2;
                        k = j - 1;
                    }
                }

                ans = max(ans, c);
            }
            cout << ans << '\n';
        }
    }

    return 0;
}