#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol t;
    cin >> t;
    while (t--)
    {
        lol n, m, r, c;
        cin >> n >> m >> r >> c;
        lol ans = 0;
        ans += max(r - 1, n - r);
        ans += max(c - 1, m - c);
        cout << ans << endl;
    }

    return 0;
}