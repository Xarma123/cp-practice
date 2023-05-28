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
        lol b[n];
        for (lol i = 0; i < n; i++)
        {
            cin >> b[i];
        }
        lol nx[n];
        for (lol i = 0; i < n; i++)
        {
            nx[i] = b[i] - i;
        }
        for (lol i = n - 2; i >= 0; i--)
        {
            nx[i] = max(nx[i + 1], nx[i]);
        }
        lol px[n];
        for (lol i = 0; i < n; i++)
        {
            px[i] = b[i] - (n - 1 - i);
        }
        for (lol i = 1; i < n; i++)
        {
            px[i] = max(px[i - 1], px[i]);
        }
        lol ans = 0;
        for (lol i = 1; i < n - 1; i++)
        {
            ans = max(ans, nx[i + 1] + px[i - 1] + b[i] + n - 1);
        }
        cout << ans << '\n';
    }

    return 0;
}