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
        lol ans = INT_MAX;
        for (lol i = 0; i < n; i++)
        {
            lol a[3] = {0, 0, 0};
            a[s[i] - 'a']++;
            for (lol j = i + 1; j < min(i + 7, n); j++)
            {
                a[s[j] - 'a']++;
                if (a[0] > a[1] && a[0] > a[2])
                {
                    ans = min(ans, (j - i + 1));
                }
            }
        }
        if (ans == INT_MAX)
            cout << -1 << endl;
        else
            cout << ans << endl;
    }

    return 0;
}