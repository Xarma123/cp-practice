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
        lol s = 0;
        lol ans = 0;

        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
            if (a[i] == 0)
            {
                a[i]++;
                ans++;
            }
            s += a[i];
        }
        if (s == 0)
            ans++;
        cout << ans << '\n';
    }
}