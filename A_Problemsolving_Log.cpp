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
        lol n;
        cin >> n;
        string s;
        cin >> s;
        lol f[26];
        memset(f, 0, sizeof(f));
        for (lol i = 0; i < n; i++)
        {
            f[s[i] - 'A']++;
        }
        lol ans = 0;
        for (lol i = 0; i < 26; i++)
        {
            if (f[i] >= i + 1)
            {
                ans++;
            }
        }
        cout << ans << '\n';
    }

    return 0;
}
