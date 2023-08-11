#include <bits/stdc++.h>
#define lol long long
using namespace std;
string to_string(char c)
{
    string a = "";
    a += c;
    return a;
}
int main()
{
    lol t;
    cin >> t;
    while (t--)
    {
        lol n;
        cin >> n;
        string a;
        cin >> a;
        set<string> x;
        for (lol i = 0; i < n; i++)
        {
            x.insert(a.substr(i, 1));
        }
        for (lol i = 1; i < n; i++)
        {
            x.insert({a.substr(i - 1, 2)});
        }
        for (lol i = 2; i < n; i++)
        {
            x.insert({a.substr(i - 2, 3)});
        }

        string ans = "";
        for (char c = 'a'; c <= 'z' && ans == ""; c++)
        {
            if (!x.count(to_string(c)))
            {
                ans = to_string(c);
            }
        }
        for (char c = 'a'; c <= 'z' && ans == ""; c++)
        {
            for (char c2 = 'a'; c2 <= 'z' && ans == ""; c2++)
            {
                if (!x.count(to_string(c) + to_string(c2)))
                {
                    ans = to_string(c) + to_string(c2);
                }
            }
        }
        for (char c = 'a'; c <= 'z' && ans == ""; c++)
        {
            for (char c2 = 'a'; c2 <= 'z' && ans == ""; c2++)
            {
                for (char c3 = 'a'; c3 <= 'z' && ans == ""; c3++)
                {
                    if (!x.count(to_string(c) + to_string(c2) + to_string(c3)))
                    {
                        ans = to_string(c) + to_string(c2) + to_string(c3);
                    }
                }
            }
        }
        cout << ans << '\n';
    }

    return 0;
}