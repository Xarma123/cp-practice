#include <bits/stdc++.h>
using namespace std;
#define lol long long
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol t;
    cin >> t;
    while (t--)
    {
        stack<lol> u, l;
        string s;
        cin >> s;
        for (lol i = 0; i < s.size(); i++)
        {
            if (s[i] == 'b')
            {
                s[i] = '\n';
                if (l.size())
                {
                    s[l.top()] = '\n';
                    l.pop();
                }
            }
            else if (s[i] == 'B')
            {
                s[i] = '\n';
                if (u.size())
                {
                    s[u.top()] = '\n';
                    u.pop();
                }
            }
            else if (s[i] >= 'a' && s[i] <= 'z')
            {
                l.push(i);
            }
            else
                u.push(i);
        }
        for (lol i = 0; i < s.size(); i++)
        {
            if (s[i] != '\n')
                cout << s[i];
        }
        cout << '\n';
    }

    return 0;
}
