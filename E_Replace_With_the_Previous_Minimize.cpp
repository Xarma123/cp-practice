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
        lol n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        if (k >= 26)
        {
            for (lol i = 0; i < s.size(); i++)
            {
                cout << 'a';
            }
            cout << endl;
        }
        else
        {
            char c = 'a';
            char c2 = '\n';
            char q = '.';
            for (lol i = 0; i < s.size(); i++)
            {

                if (s[i] <= c)
                    s[i] = 'a';
                else if (s[i] <= char(min((int)(c + k), (int)(25 + 'a'))))
                {
                    k -= s[i] - c;
                    c = s[i];
                    s[i] = 'a';
                }
                else if (c2 != '\n')
                {
                    if (s[i] <= c2 && s[i] >= t)
                        s[i] = t;
                }
                else
                {
                    c2 = s[i];
                    s[i] = char(s[i] - k);
                    k = 0;
                    t = s[i];
                }
            }
            cout << s << endl;
        }
    }

    return 0;
}