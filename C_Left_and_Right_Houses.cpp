#include <bits/stdc++.h>
using namespace std;
#define lol long long
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol t;
    cin >> t;
    while (t--)
    {
        lol n;
        cin >> n;
        string s;
        cin >> s;
        lol c[n];
        for (lol i = 0; i < n; i++)
        {
            c[i] = (s[i] - '0');
            if (i)
                c[i] += c[i - 1];
        }
        lol d = LONG_LONG_MAX;
        lol ans;
        for (lol i = 0; i <= n; i++)
        {
            lol l = 0;
            if (i)
                l += i - c[i - 1];

            lol r = 0;
            if (i < n)
            {
                r += c[n - 1];
                if (i - 1 >= 0)
                    r -= c[i - 1];
            }
            if (l >= ((i + 1) / 2ll) && r >= ((n - i + 1) / 2ll))
            {
               
                lol dn = abs(n - 2ll*i);
                if (dn < d)
                {
                    d = dn;
                    ans = i;
                }
            }
        }
        cout << ans << '\n';
    }

    return 0;
}
