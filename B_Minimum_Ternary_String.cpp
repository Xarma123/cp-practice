#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s;
    cin >> s;
    lol o = 0;
    for (lol i = 0; i < s.size(); i++)
    {
        if (s[i] == '1')
            o++;
    }
    for (lol i = 0; i < s.size(); i++)
    {
        if (s[i] == '2')
        {
            if (o > 0)
            {
                while (o--)
                {
                    cout << 1;
                }
            }
        }
        if (s[i] != '1')
            cout << s[i];
    }
    if (o > 0)
    {
        while (o--)
        {
            cout << 1;
        }
    }

    return 0;
}