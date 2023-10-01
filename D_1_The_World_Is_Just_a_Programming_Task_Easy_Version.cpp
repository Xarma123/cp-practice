#include <bits/stdc++.h>
using namespace std;
#define lol long long
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n;
    cin >> n;
    string s;
    cin >> s;
    lol c = 0;
    for (lol i = 0; i < s.size(); i++)
    {
        if (s[i] == '(')
            c++;
        else
            c--;
    }
    if (c == 0)
    {
        lol ans = LONG_LONG_MIN;
        lol l, r;
        for (lol i = 0; i < s.size(); i++)
        {
            for (lol j = 0; j < s.size(); j++)
            {
                swap(s[i], s[j]);
                lol p[s.size()];
                c = 0;
                lol mn = LONG_LONG_MAX;
                for (lol k = 0; k < s.size(); k++)
                {
                    if (s[k] == ')')
                        c--;
                    else
                        c++;
                    p[k] = c;
                    mn = min(mn, p[k]);
                }
                lol shift = 0;
                for (lol k = 0; k < s.size(); k++)
                {
                    if (p[k] == mn)
                        shift++;
                }
                if (shift > ans)
                {
                    ans = shift;
                    l = i, r = j;
                }
                swap(s[i], s[j]);
            }
        }
        cout << ans << '\n';
        cout << l + 1 << " " << r + 1 << endl;
    }
    else
    {
        cout << 0 << '\n';
        cout << 1 << " " << 1;
    }
}