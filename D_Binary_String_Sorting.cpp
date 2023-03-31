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
        string s;
        cin >> s;
        string b = s;
        sort(b.begin(), b.end());
        if (b == s)
        {
            cout << 0 << '\n';
            continue;
        }
        lol ans = LONG_LONG_MAX;
        lol p[s.size()];
        for (lol i = 0; i < s.size(); i++)
        {
            p[i] = (s[i] == '1');
            if (i)
                p[i] += p[i - 1];
        }
        lol suf[s.size()];
        for (lol i = s.size() - 1; i >= 0; i--)
        {
            suf[i] = (s[i] == '0');
            if (i < s.size() - 1)
                suf[i] += suf[i + 1];
        }
        for (lol i = 1; i < s.size(); i++)
        {
            if (s[i] == '0' && s[i - 1] == '1')
            {
                lol q = 0;
                if (i - 2 >= 0)
                    q += p[i - 2];
                if (i + 1 < s.size())
                    q += suf[i + 1];
                ans = min(ans, (long long)(q * 1ll * (1e12 + 1) + 1e12));
            }
        }
        for (lol i = -1; i < s.size(); i++)
        {
            lol q = 0;
            if (i + 1 < s.size())
                q += suf[i + 1];
            if (i >= 0)
            {
                q += p[i];
            }
            ans = min(ans, (long long)(q * 1ll * (1e12 + 1)));
        }

        cout << ans << '\n';
    }
    return 0;
}