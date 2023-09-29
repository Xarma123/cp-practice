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
        lol x;
        cin >> x;
        string s;
        cin >> s;
        lol m = 1e9 + 7;
        lol ans = s.size();
        for (lol i = 0; i < x; i++)
        {
            if (s.size() < x)
            {
                lol c = s[i] - '1';

                string add = s.substr(i + 1);
                while (c--)
                {
                    s += add;
                }
                ans = s.size();
            }
            else
            {
                lol c = s[i] - '1';
                lol add = ((ans - i - 1) % m + m) % m;
                while (c--)
                {
                    ans += add;
                    ans %= m;
                }
            }
        }
        cout << ans << '\n';
    }
}