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
        string a(2ll * s.size(), '(');
        for (lol i = s.size(); i < a.size(); i++)
        {
            a[i] = ')';
        }
        string b(2ll * s.size(), '0');
        for (lol i = 0; i < b.size(); i++)
        {
            if (i % 2 == 0)
                b[i] = '(';
            else
                b[i] = ')';
        }
        bool f = true;
        for (lol i = 0; i < (long long)a.size(); i++)
        {
            if (i + s.size() - 1 < a.size())
            {
               
                if (a.substr(i, s.size()) == s)
                    f = false;
            }
        }
        if (f)
        {
            cout << "YES\n";
            cout << a << '\n';
            continue;
        }
        f = true;
        for (lol i = 0; i < (long long)b.size(); i++)
        {
            if (i + s.size() - 1 < b.size())
            {
                if (b.substr(i, s.size()) == s)
                    f = false;
            }
        }
        if (f)
        {
            cout << "YES\n";
            cout << b << '\n';
            continue;
        }
        cout << "NO\n";
    }
}