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
        lol i = 0;
        while (i < s.size() && s[i] == 'a')
            i++;
        if (i == s.size())
        {
            cout << "NO\n";
        }
        else
        {
            cout << "YES\n";
            if (i < s.size() - i - 1)
            {
                lol j = s.size() - i - 1;
                for (lol k = 0; k < s.size(); k++)
                {
                    cout << s[k];
                    if (k == j)
                        cout << 'a';
                }
            }
            else
            {
                lol j = s.size() - i - 1;
                for (lol k = 0; k < s.size(); k++)
                {
                    if (k == j)
                        cout << 'a';
                    cout << s[k];
                }
            }
            cout << '\n';
        }
    }
}