#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol q;
    cin >> q;
    while (q--)
    {
        lol n, t;
        cin >> n >> t;
        lol a[n], b[n];
        for (lol i = 0; i < n; i++)
            cin >> a[i];
        for (lol i = 0; i < n; i++)
            cin >> b[i];
        lol ans = -1;
        lol mx = 0;
        for (lol i = 0; i < n; i++)
        {
            if (a[i] + i <= t && b[i] > mx)
                ans = i + 1, mx = b[i];
        }
        cout << ans << '\n';
    }

    return 0;
}