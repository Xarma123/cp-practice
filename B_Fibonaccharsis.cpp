#include <bits/stdc++.h>
using namespace std;
#define lol long long
lol solve(lol a, lol b)
{

    if (b >= 0 && a >= b)
    {
        return 1 + solve(b, a - b);
    }

    return 0;
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol t;
    cin >> t;
    while (t--)
    {
        lol n, k;
        cin >> n >> k;
        lol ans = 0;
        for (lol i = (n + 1) / 2; i <= n; i++)
        {
            lol c = solve(n, i) + 1;

            if (c >= k)
                ans++;
        }
        cout << ans << '\n';
    }
}