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
        string s;
        cin >> n >> s;
        char prv = '\n';
        lol ans = 0, sub = 0;
        for (lol i = 0; i < n; i += 2)
        {
            if (s[i] != s[i + 1])
                ans++;
            else
            {
                if (prv != s[i])
                    sub++;
                prv = s[i];
            }
        }
        if (sub == 0)
            sub++;
        cout << ans << " " << sub << "\n";
    }
}