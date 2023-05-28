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
        lol n = s.size();
        bool o = true;
        for (lol i = 0; i < n; i++)
        {
            if (s[i] == '0')
                o = false;
        }
        if (o)
        {
            cout << n * 1ll * n << '\n';
        }
        else
        {
            s = s + s;
            lol ans = 0;
            for (lol i = 0; i < s.size(); i++)
            {
                if (s[i] == '1')
                {
                    lol j = i + 1;
                    while (j < s.size() && s[j] == '1')
                        j++;
                    lol l = min(j - i, n);
                    lol st = 0, e = n + 1;
                    while (st != e - 1)
                    {
                        lol r = (st + e) / 2;
                        if (r == 0)
                        {
                            st = 0;
                        }
                        else
                        {
                            if ((r + 1) * 1ll * (l - r) > (r)*1ll * (l - r + 1))
                                st = r;
                            else
                                e = r;
                        }
                    }
                   
                    ans = max(ans, (st + 1) * 1ll * (l - st));

                    i = j - 1;
                }
            }
            cout << ans << '\n';
        }
    }

    return 0;
}