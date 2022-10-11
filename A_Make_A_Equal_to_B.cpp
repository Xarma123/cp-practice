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
        lol a[n], b[n];
        lol oa = 0, ob = 0;
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
            if (a[i])
                oa++;
        }
        lol ans = 0;
        for (lol i = 0; i < n; i++)
        {
            cin >> b[i];
            if (b[i] != a[i])
                ans++;
            if (b[i])
                ob++;
        }

        ans = min(ans, abs(oa - ob) + 1);
        cout << ans << endl;
    }

    return 0;
}