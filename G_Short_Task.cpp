#include <bits/stdc++.h>
using namespace std;
#define lol long long
lol d[10000005];
lol s[10000005];
lol ans[10000005];
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    d[1] = 1;
    for (lol i = 2; i * 1ll * i < 10000005; i++)
    {
        if (d[i] == 0)
        {
            d[i] = i;
            for (lol j = i * 1ll * i; j < 10000005; j += i)
            {
                if (d[j] == 0)
                    d[j] = i;
            }
        }
    }
    s[1] = 1;

    for (lol i = 2; i < 10000005; i++)
    {
        if (d[i] == 0)
        {
            s[i] = i + 1;
            d[i] = i;
        }
        else
        {
            lol j = i;
            s[i] = 1;
            while (j % d[i] == 0)
            {
                j /= d[i];
                s[i] = s[i] * 1ll * d[i] + 1;
            }
            s[i] *= s[j];
        }
        if (s[i] < 10000005 && ans[s[i]] == 0)
            ans[s[i]] = i;
    }
    ans[1] = 1;
    lol t;
    cin >> t;
    while (t--)
    {
        lol c;
        cin >> c;
        if (ans[c] != 0)
            cout << ans[c] << '\n';
        else
            cout << -1 << '\n';
    }
}