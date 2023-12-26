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
        lol n, m;
        cin >> n >> m;
        string s, t;
        cin >> s >> t;
        bool f = true;
        for (lol i = 1; i < n; i++)
        {
            if (s[i] == s[i - 1])
                f = false;
        }
        if (f)
        {
            cout << "Yes\n";
            continue;
        }
        f = true;
        for (lol i = 1; i < m; i++)
        {
            if (t[i] == t[i - 1])
                f = false;
        }
        if ((!f) || (t[0] != t[m - 1]))
        {
            cout << "No\n";
            continue;
        }
        f = true;
        for (lol i = 1; i < n; i++)
        {
            if (s[i] == s[i - 1])
            {
                if (s[i] == t[0])
                    f = false;
            }
        }
        if (f)
            cout << "Yes\n";
        else
            cout << "No\n";
    }

    return 0;
}
