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
        lol n = s.size();
        if (s[0] == '?')
            s[0] = '0';
        for (lol i = 1; i < n; i++)
        {
            if (s[i] == '?')
                s[i] = s[i - 1];
        }
        cout << s << '\n';
    }
}