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
        lol n, x;
        cin >> n >> x;
        string s;
        cin >> s;
        lol p[n];
        for (lol i = 0; i < n; i++)
        {
            p[i] = 0;
            if (s[i] == '0')
                p[i]++;
            else
                p[i]--;
            if (i)
                p[i] += p[i - 1];
        }

        lol ans = 0;
        for (lol i = 0; i < n; i++)
        {
            if (p[n - 1] == 0 && p[i] == x)
            {
                ans = -1;
                break;
            }
            if (p[n - 1] != 0)
            {
                if (((long long)abs((x - p[i])) % ((long long)abs(p[n - 1]))) == 0)
                {
                    if (((x - p[i]) / p[n - 1]) >= 0)
                        ans++;
                }
            }
        }
        if (ans == -1)
        {
       
                cout << ans << '\n';
        }
        else
        {
            if (x == 0)
                ans++;
            cout << ans << '\n';
        }
    }
}