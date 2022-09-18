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
    map<char, lol> x;
    lol q = 0;
    for (lol i = 0; i < 26&&i<s.size(); i++)
    {
        if (s[i] != '?')
            x[s[i]]++;
        else
        {
            q++;
        }
    }
    lol st = -1;
    if (x.size() + q == 26)
    {
        st = 0;
    }
    for (lol i = 26; i < s.size() && st == -1; i++)
    {
        if (s[i] != '?')
            x[s[i]]++;
        else
        {
            q++;
        }

        if (s[i - 26] != '?')
        {
            x[s[i - 26]]--;
            if (x[s[i - 26]] == 0)
            {
                x.erase(s[i - 26]);
            }
        }
        else
        {
            q--;
        }
        if (x.size() + q == 26)
        {
            st = i - 25;
        }
    }
    if (st == -1)
        cout << -1;
    else
    {
        bool f[26];
        memset(f, false, sizeof(f));

        for (lol i = st; i < st + 26; i++)
        {
            if (s[i] != '?')
            {
                f[s[i] - 'A'] = true;
            }
        }
        for (lol i = st; i < st + 26; i++)
        {
            if (s[i] == '?')
            {
                for (lol j = 0; j < 26; j++)
                {
                    if (!f[j])
                    {
                        s[i] = char('A' + j);
                        f[j] = true;
                        break;
                    }
                }
            }
        }
        for (lol i = 0; i < s.size(); i++)
        {
            if (s[i] == '?')
                s[i] = 'A';
        }
        cout << s;
    }

    return 0;
}