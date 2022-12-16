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
        lol n;
        cin >> n;
        string s;
        cin >> s;
        lol tot, one, equ;
        lol ans = 0;
        lol m = 998244353;
        for (lol i = 0; i < n; i++)
        {
            if (i == 0)
            {
                tot = 1;
                equ = 1;
                one = 0;
            }
            else
            {
                if (s[i] == s[i - 1])
                {
                    tot = (tot * 2ll) % m;
                    one = (one + equ) % m;
                    // lol nequ = equ;
                }
                else
                {
                    tot = equ;
                    one = 0;
                }
            }

            ans = (ans + tot) % m;
        }
        cout << ans << endl;
    }

    return 0;
}