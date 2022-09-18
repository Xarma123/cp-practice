#include <bits/stdc++.h>
#define lol long long
using namespace std;
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
        bool u[26];
        memset(u, false, sizeof(u));
        lol ans = 0;
        for (lol i = 0; i < s.size(); i++)
        {
            if (u[s[i] - 'A'])
                ans++;
            else
            {
                ans += 2;
                u[s[i] - 'A'] = true;
            }
        }
        cout << ans << endl;
    }

    return 0;
}