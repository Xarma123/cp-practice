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
        char c = '1';
        lol ans = 0;
        for (lol i = 0; i < s.size(); i++)
        {
            if (c != '0' && s[i] != '0')
            {
                ans += abs(s[i] - c);
            }
            else if (c != '0')
            {
                ans += ('9' - c) + 1;
            }
            else if (s[i] != '0')
            {
                ans += ('9' - s[i]) + 1;
            }
            c = s[i];
        }
        cout << ans + s.size() << '\n';
    }

    return 0;
}
