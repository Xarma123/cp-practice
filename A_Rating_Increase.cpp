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
        lol b = 1;
        for (lol i = 1; i < s.size(); i++)
        {
            if (s[i] == '0')
            {
                b = i + 1;
            }
            else
                break;
        }
        if (b == s.size())
        {
            cout << -1 << '\n';
            continue;
        }
        string a = s.substr(0, b);
        string c = s.substr(b);
        lol a1 = stol(a);
        lol a2 = stol(c);
        if (a1 < a2)
        {
            cout << a << " " << c << '\n';
        }
        else
            cout << -1 << '\n';
    }

    return 0;
}
