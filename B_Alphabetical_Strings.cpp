#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        bool ans = true;
        lol p = 0;
        char last = char('z' + 1);

        bool x[s.size()];
        for (lol i = 0; i < s.size(); i++)
        {
            x[i] = false;
        }

        while (s[p] != 'a')
        {
            if ((s[p] - 'a') >= s.size())
            {
                ans = false;
                break;
            }
            if (s[p] > last || (x[s[p] - 'a']))
            {
                ans = false;
                break;
            }

            last = s[p];
            x[(last - 'a')] = true;
            p++;
            if (p == s.size())
                break;
        }

        last = 'a';
        x[last - 'a'] = true;
        p++;

        while (p < s.size())
        {
            if ((s[p] - 'a') >= s.size())
            {
                ans = false;
                break;
            }
            if (s[p] < last || (x[s[p] - 'a']))
            {
                ans = false;
                break;
            }
            last = s[p];
            x[(last - 'a')] = true;
            p++;
        }
        if (ans)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}