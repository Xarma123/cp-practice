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
        for (lol i = 0; i < s.size(); i++)
        {
            if (i % 2 == 0)
            {
                if (s[i] == 'a')
                    s[i] = 'b';
                else
                    s[i] = 'a';
            }
            else
            {
                if (s[i] == 'z')
                    s[i] = 'y';
                else
                    s[i] = 'z';
            }
        }
        cout << s << '\n';
    }
}