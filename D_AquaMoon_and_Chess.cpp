#include <bits/stdc++.h>
using namespace std;
#define lol long long
lol m = 998244353;
lol f[100005];
lol inf[100005];
lol inv(lol i)
{
    return i <= 1 ? i : m - (long long)(m / i) * inv(m % i) % m;
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    f[0] = 1;
    for (lol i = 1; i < 100005; i++)
    {
        f[i] = (f[i - 1] * 1ll * i) % m;
    }
    inf[0] = inv(1);
    for (lol i = 1; i < 100005; i++)
    {
        inf[i] = (inf[i - 1] * 1ll * inv(i)) % m;
    }

    lol t;
    cin >> t;
    while (t--)
    {
        lol n;
        cin >> n;
        string s;
        cin >> s;
        lol g = 0, z = 0;
        for (lol i = 0; i < n; i++)
        {
            if (s[i] == '0')
                z++;
            else
            {
                lol j = i + 1;
                while (j < n && s[j] == s[j - 1])
                {
                    j++;
                }
                g += (j - i) / 2;
                i = j - 1;
            }
        }
        cout << ((((f[g + z] * 1ll * inf[g]) % m) * 1ll * inf[z]) % m) << '\n';
    }
}