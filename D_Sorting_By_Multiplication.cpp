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
        lol n;
        cin >> n;
        lol a[n];
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        lol s[n + 1];
        s[n] = 0;
        s[n - 1] = 0;
        for (lol i = n - 2; i >= 0; i--)
        {
            if (a[i] >= a[i + 1])
            {
                s[i] = s[i + 1] + 1;
            }
            else
                s[i] = s[i + 1];
        }
        lol ans = s[0];
        lol c = 0;
        for (lol i = 0; i < n; i++)
        {
            if (i == 0)
            {
                ans = min(ans, s[i + 1] + 1 + c);
            }
            else
            {
                if (a[i] >= a[i - 1])
                {
                    c++;
                }
                ans = min(ans, s[i + 1] + 1 + c);
            }
        }
        cout << ans << '\n' ;
    }
}