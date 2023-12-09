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
        lol ans = 0;
        lol c = 0;
        for (lol i = 0; i < n; i++)
        {
            if (s[i] == '#')
                continue;
            lol j = i + 1;
            while (j < n && s[j] == '.')
                j++;
            if (j - i == 1)
                ans++;
            else if (j - i == 2)
                ans += 2;
            else
            {
                c++;
            }
            i = j - 1;
        }
        if (c)
        {
            ans = 2;
        }
        cout << ans << '\n';
    }

    return 0;
}
