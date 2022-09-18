#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol t;
    cin >> t;
    while (t--)
    {
        lol n;
        cin >> n;
        string s;
        cin >> s;
        lol l = 0;
        lol ans = 0;
        for (lol i = 0; i < s.size(); i++)
        {
            if (s[i] == '(')
            {
                l++;
            }
            else
            {
                l--;
                if (l < 0)
                {
                    ans++;
                    l = 0;
                }
            }
        }
        cout << ans << endl;
    }

    return 0;
}