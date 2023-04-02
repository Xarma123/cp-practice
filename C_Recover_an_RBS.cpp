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
        string s;
        cin >> s;
        lol q = 0;
        lol sum = 0;
        for (lol i = 0; i < s.size(); i++)
        {
            if (s[i] == '?')
                q++;
            else if (s[i] == ')')
                sum--;
            else
                sum++;
        }
        sum = -sum;
        if ((sum + q) % 2 == 0)
        {
            lol o = (sum + q) / 2;
            lol c = q - o;
            if (o >= 0 && c >= 0)
            {
                bool ans = true;
                lol cs = 0;

                for (lol i = 0; i < s.size(); i++)
                {
                    if (s[i] == '(')
                    {
                        cs++;
                    }
                    else if (s[i] == ')')
                        cs--;
                    else
                    {
                        if (o > 0)
                        {
                            cs++;
                            o--;
                        }
                        else
                        {
                            cs--;
                        }
                    }
                    if (cs < 0)
                        ans = false;
                }
                if (!ans)
                {
                    cout << "NO\n";
                }
                else
                {
                    o = q - c;
                    if (o > 0 && c > 0)
                    {
                        for (lol i = 0; i < s.size(); i++)
                        {
                            if (s[i] == '?')
                            {
                                if (o > 0)
                                {
                                    s[i] = 'a';
                                    o--;
                                }
                                else
                                {
                                    s[i] = 'b';
                                }
                            }
                        }
                        lol l;
                        for (lol i = s.size() - 1; i >= 0; i--)
                        {
                            if (s[i] == 'b')
                                l = i;
                            else if (s[i] == 'a')
                            {
                                swap(s[i], s[l]);
                                break;
                            }
                        }
                        for (lol i = 0; i < s.size(); i++)
                        {
                            if (s[i] == 'a')
                                s[i] = '(';
                            else if (s[i] == 'b')
                                s[i] = ')';
                        }
                        cs = 0;
                        ans = false;
                        for (lol i = 0; i < s.size(); i++)
                        {
                            if (s[i] == '(')
                                cs++;
                            else
                                cs--;
                            if (cs < 0)
                            {
                                ans = true;
                            }
                        }
                        if (ans)
                            cout << "YES\n";
                        else
                            cout << "NO\n";
                    }
                    else
                        cout << "YES\n";
                }
            }
            else
            {
                cout << "NO\n";
            }
        }
        else
            cout << "NO\n";
    }

    return 0;
}