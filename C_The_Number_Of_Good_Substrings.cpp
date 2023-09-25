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
        lol ans = 0;
        lol p[s.size()];
        p[0] = 0;
        for (lol i = 1; i < s.size(); i++)
        {
            if (s[i - 1] == '0')
                p[i] = p[i - 1] + 1;
            else
                p[i] = 0;
        }

        for (lol d = 1; d < 30; d++)
        {
            if (d > s.size())
                break;
            lol c = 1;
            lol v = 0;
            for (lol j = (long long)s.size() - 1; j >= (long long)s.size() - d; j--)
            {
                if (s[j] == '1')
                    v += c;
                c = c * 2ll;
            }
            c /= 2;
            for (lol j = (long long)s.size() - d; j >= 0; j--)
            {
                if (j != s.size() - d)
                {
                    v /= 2;
                    if (s[j] == '1')
                        v += c;
                }
                if (v < 29 && v > d)
                    continue;
                lol z = v - d;
                if (z == 0)
                    ans++;
                else if (d == 29)
                {
                    if (z >= 0)
                    {
                        if (p[j] >= z)
                        {
                            ans++;
                        }
                    }
                }
            }
        }
        cout << ans << '\n';
    }
}