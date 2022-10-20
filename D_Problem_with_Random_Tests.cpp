#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n;
    cin >> n;
    string s;
    cin >> s;
    lol st = -1;
    for (lol i = 0; i < n; i++)
    {
        if (s[i] == '1')
        {
            st = i;
            break;
        }
    }
    if (st == -1)
    {
        cout << 0;
    }
    else
    {
        s = s.substr(st);
        string s2 = s;
        for (lol i = 0; i < s2.size(); i++)
            s2[i] = char(1 - (s2[i] - '0') + '0');
        st = 0;
        for (; st < n; st++)
        {
            if (s2[st] == '1')
                break;
        }
        if (st == n)
        {
            cout << s << endl;
        }
        else
        {
            s2 = s2.substr(st);
            lol sz = s2.size();
            s2 = s2 + "$" + s;
            n = s2.size();
            lol lps[n];
            lps[0] = 0;
            lol i = 1, j = 0;
            while (i < n)
            {
                if (s2[i] == s2[j] || s2[j] == '0')
                {
                    lps[i] = j + 1;
                    i++;
                    j++;
                }
                else
                {
                    if (j == 0)
                    {
                        lps[i] = 0;
                        i++;
                    }
                    else
                    {
                        j = lps[j - 1];
                    }
                }
            }
            bool f = false;
            lol ans = 0;

            for (lol i = 0; i < n; i++)
            {
                if (s2[i] == '$')
                {
                    f = true;
                    continue;
                }
                if (!f)
                    continue;
                if (n - i >= sz)
                    ans = max(ans, lps[i]);
            }
            lol c = 0;
            for (lol i = 0; i < ans; i++)
            {
                if (s2[i] == '1')
                    c++;
            }

            for (lol i = 0; i < s.size(); i++)
            {
                if (s[i] == '0' && c > 0)
                {
                    s[i] = '1';
                    c--;
                }
            }
            cout << s << endl;
        }
    }

    return 0;
}