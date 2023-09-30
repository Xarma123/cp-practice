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
        bool ans = true;
        for (lol i = 0; i < s.size(); i++)
        {
            if (s[i] != '?')
            {
                if (i - 1 >= 0 && s[i - 1] == s[i])
                    ans = false;
            }
            else
            {
                if (i - 1 >= 0 && i + 1 < s.size())
                {
                    if (s[i - 1] != 'a' && s[i + 1] != 'a')
                        s[i] = 'a';
                    else if (s[i - 1] != 'b' && s[i + 1] != 'b')
                        s[i] = 'b';
                    else
                        s[i] = 'c';
                }
                else if (i - 1 >= 0)
                {
                    if (s[i - 1] != 'a')
                        s[i] = 'a';
                    else if (s[i - 1] != 'b')
                        s[i] = 'b';
                    else
                        s[i] = 'c';
                }
                else if (i + 1 < s.size())
                {
                    if (s[i + 1] != 'a')
                        s[i] = 'a';
                    else if (s[i + 1] != 'b')
                        s[i] = 'b';
                    else
                        s[i] = 'c';
                }
                else
                    s[i] = 'a';
            }
        }
        if (!ans)
            cout << -1;
        else
            cout << s;
        cout << '\n';
    }
}