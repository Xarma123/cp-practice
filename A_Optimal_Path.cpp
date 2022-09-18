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
        lol n, m;
        cin >> n >> m;
        lol ans1 = m * 1ll * (m + 1) / 2;
        for (lol i = 1; i < n; i++)
        {
            ans1 += m * 1ll * i + m;
        }
        lol ans2 = 0;
        for (lol i = 0; i < n; i++)
        {
            ans2 += i * 1ll * m + 1;
        }
        for (lol j = 1; j < m; j++)
        {
            ans2 += (n - 1) * 1ll * m + j + 1;
        }
        cout << min(ans2, ans1) << endl;
    }

    return 0;
}