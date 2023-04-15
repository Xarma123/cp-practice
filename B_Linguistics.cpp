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
        lol a, b, c, d;
        cin >> a >> b >> c >> d;
        string s;
        cin >> s;
        lol ca = a + c + d;
        for (auto c : s)
        {
            if (c == 'A')
                ca--;
        }
        if (ca == 0)
        {
            // abababa
            // ababab
            // baba
            // babab
            vector<lol> g1a, g2a;
            vector<lol> g1b, g2b;

            for (lol i = 0; i < s.size() - 1; i++)
            {
                if (s[i] == 'A' && s[i + 1] == 'B')
                {
                    lol j = i + 1;
                    while (j < s.size() && s[j] != s[j - 1])
                        j++;
                    if (s[j - 1] == 'A')
                    {
                        g1a.push_back(j - i);
                    }
                    else
                        g2a.push_back(j - i);
                    i = j - 1;
                }
                else if (s[i] == 'B' && s[i + 1] == 'A')
                {
                    lol j = i + 1;
                    while (j < s.size() && s[j] != s[j - 1])
                        j++;
                    if (s[j - 1] == 'B')
                    {
                        g1b.push_back(j - i);
                    }
                    else
                        g2b.push_back(j - i);
                    i = j - 1;
                }
            }
            sort(g1a.begin(), g1a.end());
            sort(g2a.begin(), g2a.end());
            sort(g1b.begin(), g1b.end());
            sort(g2b.begin(), g2b.end());

            for (auto e : g2a)
            {

                if (c >= (e / 2))
                {
                    c -= (e / 2);
                }
                else
                {
                    e -= 2ll * c;
                    c = 0;
                    d -= (e / 2ll) - 1;
                }
            }
            for (auto e : g2b)
            {
                if (d >= (e / 2))
                {
                    d -= (e / 2);
                }
                else
                {
                    e -= 2ll * (d);
                    d = 0;
                    c -= (e / 2) - 1;
                }
            }

            // ababa
            for (auto e : g1a)
            {
                if (c >= (e / 2))
                {
                    c -= (e / 2ll);
                }
                else
                {
                    e -= 2ll * c;
                    c = 0;
                    d -= (e / 2ll);
                }
            }
            // babab
            for (auto e : g1b)
            {
                if (c >= (e / 2))
                {
                    c -= (e / 2ll);
                }
                else
                {
                    e -= 2ll * c;
                    c = 0;
                    d -= (e / 2ll);
                }
            }

            if (c <= 0 && d <= 0)
                cout << "YES\n";
            else
                cout << "NO\n";
        }
        else
            cout << "NO\n";
    }

    return 0;
}