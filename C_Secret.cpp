#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n, k;
    cin >> n >> k;
    // 1 2 3 4 5 . . . .  n
    if (k * 3ll <= n)
    {
        lol ans[n];
        ans[0] = k;
        lol p = 1;
        lol i;
        for (i = 1; p <= k; i += 2, p++)
        {
            ans[i] = p;
            ans[i + 1] = p;
        }
        p = k - 1;
        for (; p >= 1; i++, p--)
        {
            ans[i] = p;
        }
        for (; i < n; i++)
        {
            ans[i] = 1;
        }
        for (i = 0; i < n; i++)
        {
            cout << ans[i] << " ";
        }
    }
    else
        cout << -1;

    return 0;
}