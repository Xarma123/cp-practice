#include <bits/stdc++.h>
#define lol long long
using namespace std;

lol ans(string s, char c)
{

    if (s.size() == 1)
    {
        return s[0] != c;
    }
    lol md = s.size() / 2;
    lol l = ans(string(s.begin() + md, s.end()), char(c + 1));
    l += (s.size() / 2) - count(s.begin(), s.begin() + md, c);
    lol r = ans(string(s.begin(), s.begin() + md), char(c + 1));
    r += (s.size() / 2) - count(s.begin() + md, s.end(), c);

    return min(l, r);
}
int main()
{
    lol t;
    cin >> t;
    while (t--)
    {
        lol n;
        cin >> n;
        string s;
        cin >> s;

        cout << ans(s, 'a') << endl;
    }

    return 0;
}