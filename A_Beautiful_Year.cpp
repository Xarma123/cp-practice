#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s;
    cin >> s;
    lol i = -1;
    set<lol> y;
    while (i < s.size() && y.size() == i + 1)
    {
        i++;
        if (i < s.size())
            y.insert(s[i] - '0');
    }
    if (i == s.size())
        i--;
    for (; i >= 0; i--)
    {
        lol g = s[i] - '0';
        g++;
        set<lol> x;
        for (lol j = 0; j < i; j++)
        {
            x.insert(s[j] - '0');
        }
        while (x.count(g))
        {
            g++;
        }
        if (g < 10)
        {
            s[i] = char('0' + g);
            x.insert(g);
            g = 0;
            for (lol j = i + 1; j < s.size(); j++)
            {
                while (x.count(g))
                    g++;
                s[j] = char('0' + g);
                x.insert(g);
            }

            break;
        }
    }
    cout << s;

    return 0;
}