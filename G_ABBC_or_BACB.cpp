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
        if (s[0] == 'B' || s.back() == 'B')
        {
            lol ans = 0;
            for (auto e : s)
            {
                if (e == 'A')
                    ans++;
            }
            cout << ans << '\n';
        }
        else
        {
            lol mn = LONG_LONG_MAX;
            lol ans = 0;
            bool f = true;
            for (lol i = 0; i < s.size(); i++)
            {

                lol j = i + 1;
                while (j < s.size() && s[j] == s[j - 1])
                {
                    j++;
                }
                if (s[i] == 'A')
                {
                    ans += j - i;
                    mn = min(mn, j - i);
                }
                else if (j - i > 1)
                    f = false;
                i = j - 1;
            }
            if (f)
                ans -= mn;
            cout << ans << '\n';
        }
    }
}