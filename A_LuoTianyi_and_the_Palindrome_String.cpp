#include <bits/stdc++.h>
using namespace std;
#define lol long long
int main()
{
    lol t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        char c = s[0];
        lol i;
        for (i = 0; i < s.size(); i++)
        {
            if (s[i] != c)
                break;
        }
        if (i == s.size())
        {
            cout << -1 << '\n';
        }
        else
        {
            cout << s.size() - 1 << '\n';
        }
    }
}