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
        string s;
        cin >> s;
        lol m = 998244353;
        lol fact[s.size() + 1];
        fact[0] = 1;
        for (lol i = 1; i <= s.size(); i++)
        {
            fact[i] = (fact[i - 1] * 1ll * i) % m;
        }

        // 1010
        lol c1 = 0;
        char c = '1';
        lol w1 = 1;
        for (lol i = 0; i < s.size(); i++)
        {
            if (s[i] == c)
            {
                lol j = i + 1;
                while (j < s.size() && s[j] == s[i])
                {
                    j++;
                }
                w1 = (w1 * 1ll * (j - i)) % m;
                c1 += j - i - 1;
                i = j - 1;
                if (c == '1')
                    c = '0';
                else
                    c = '1';
            }
            else
            {
                lol j = i + 1;
                while (j < s.size() && s[j] == s[i])
                {
                    j++;
                }
                c1 += j - i;
                i = j - 1;
            }
        }
        w1 = (w1 * 1ll * fact[c1]) % m;
        // 0101
        lol c2 = 0;
        c = '0';
        lol w2 = 1;
        for (lol i = 0; i < s.size(); i++)
        {
            if (s[i] == c)
            {
                lol j = i + 1;
                while (j < s.size() && s[j] == s[i])
                {
                    j++;
                }
                w2 = (w2 * 1ll * (j - i)) % m;
                c2 += j - i - 1;
                i = j - 1;

                if (c == '1')
                    c = '0';
                else
                    c = '1';
            }
            else
            {
                lol j = i + 1;
                while (j < s.size() && s[j] == s[i])
                {
                    j++;
                }
                c2 += j - i;
                i = j - 1;
            }
        }
        w2 = (w2 * 1ll * fact[c2]) % m;
        if (c1 == c2)
        {
            cout << c1 << " " << w1 + w2 << '\n';
        }
        else if (c1 < c2)
        {
            cout << c1 << " " << w1 << '\n';
        }
        else
            cout << c2 << " " << w2 << '\n';
    }
}