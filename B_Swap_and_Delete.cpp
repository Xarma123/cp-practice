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
        string s;
        cin >> s;
        lol p[s.size()];
        for (lol i = 0; i < s.size(); i++)
        {
            p[i] = (s[i] - '0');
            if (i)
                p[i] += p[i - 1];
        }
        lol avone = p[s.size() - 1];
        lol avzero = (long long)s.size() - avone;
        bool f = true;
        for (lol i = s.size() - 1; i >= 0; i--)
        {
            lol z = p[i];
            lol o = i + 1 - p[i];
            if (avone >= o && avzero >= z)
            {
                cout << (long long)s.size() - 1 - i << '\n';
                f = false;
                break;
            }
        }
        if (f)
            cout << s.size() << '\n';
    }

    return 0;
}
