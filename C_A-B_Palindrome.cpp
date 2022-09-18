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
        lol a, b;
        cin >> a >> b;
        string s;
        cin >> s;
        lol st = 0;
        lol e = s.size() - 1;
        bool ans = true;
        while (st <= e)
        {

            if (s[st] != '?' && s[e] != '?')
            {
                if (st == e)
                {
                    if (s[st] == '0')
                        a--;
                    else if (s[st] == '1')
                        b--;
                    st++;
                    e--;
                    continue;
                }
                else if (s[st] != s[e])
                    ans = false;
                else if (s[st] == '0')
                    a -= 2;
                else
                    b -= 2;
            }

            if (s[st] == '?' && s[e] == '?')
            {
                st++;
                e--;
                continue;
            }
            if (s[st] == '?')
            {
                s[st] = s[e];
                if (s[e] == '0')
                    a -= 2;
                else
                    b -= 2;
            }
            if (s[e] == '?')
            {
                s[e] = s[st];
                if (s[st] == '0')
                    a -= 2;
                else
                    b -= 2;
            }

            if (a < 0 || b < 0)
                ans = false;
            st++;
            e--;
        }

        st = 0;
        e = s.size() - 1;
        while (st <= e)
        {
            if (s[st] == '?' && s[e] == '?')
            {
                if (st == e)
                {
                    if (a > 0)
                    {
                        s[st] = '0';
                        a--;
                    }
                    else
                    {
                        s[st] = '1';
                        b--;
                    }
                }
                else
                {
                    if (a > 1)
                    {
                        s[st] = '0';
                        s[e] = '0';
                        a -= 2;
                    }
                    else
                    {
                        s[st] = '1';
                        s[e] = '1';
                        b -= 2;
                    }
                }
            }
            st++;
            e--;
        }
        if (ans && (a == 0 && b == 0))
            cout << s << endl;
        else
            cout << -1 << endl;
    }

    return 0;
}