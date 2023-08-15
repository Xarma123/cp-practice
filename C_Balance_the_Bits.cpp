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
        lol n;
        cin >> n;
        string s;
        cin >> s;
        string a(n, '0'), b(n, '0');
        bool f = true;
        lol o = 0;
        lol o2 = 0;
        for (lol i = 0; i < n; i++)
        {
            if (s[i] == '0')
            {

                if (f)
                {
                    o++;
                    a[i] = '(';
                    b[i] = ')';
                    f = false;
                }
                else
                {
                    o2++;
                    a[i] = ')';
                    b[i] = '(';
                    f = true;
                }
            }
        }
        for (lol i = 0; i < n; i++)
        {
            if (a[i] == '0')
            {
                if (o < n / 2)
                {
                    a[i] = '(';
                    o++;
                }
                else
                    a[i] = ')';
            }
        }
        for (lol i = 0; i < n; i++)
        {
            if (b[i] == '0')
                b[i] = a[i];
        }

        bool ans = true;
        lol c = 0;
        for (lol i = 0; i < n; i++)
        {
            if (a[i] == '(')
                c++;
            else
                c--;
            if (c < 0)
                ans = false;
        }
        if (c != 0)
            ans = false;
        for (lol i = 0; i < n; i++)
        {
            if (b[i] == '(')
                c++;
            else
                c--;
            if (c < 0)
                ans = false;
        }
        if (c != 0)
            ans = false;
        if (ans)
        {
            cout << "YES\n";
            cout << a << '\n';
            cout << b << '\n';
        }
        else
            cout << "NO\n";
    }
}