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
        if (s.size() % 2 != 0)
            cout << "NO\n";
        else
        {
            lol n = s.size();
            n /= 2;
            for (lol i = 0; i < s.size(); i++)
            {
                if (s[i] == '(')
                    n--;
            }
            if (n < 0)
            {
                cout << "NO\n";
                continue;
            }
            lol c = 0;
            for (lol i = 0; i < s.size(); i++)
            {
                if (s[i] == '?')
                {
                    if (n)
                    {
                        n--;
                        s[i] = '(';
                    }
                    else
                        s[i] = ')';
                }
                if (s[i] == ')')
                    c--;
                else
                    c++;
                if (c < 0)
                    break;
            }
            if (c != 0)
                cout << "NO\n";
            else
                cout << "YES\n";
        }
    }
}