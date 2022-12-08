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
        lol n, x, c;
        cin >> n >> x >> c;
        lol ans = 0;
        for (lol i = 0; i < n; i++)
        {
            lol v;
            cin >> v;
            ans += v;
            if (x - v - c >= 0)
                ans += x - v - c;
        }
        cout << ans << endl;
    }

    return 0;
}