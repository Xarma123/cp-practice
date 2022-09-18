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
        lol a[n + 1];
        lol c[n + 1];
        c[0] = 0;
        lol ans = 0;
        for (lol i = 1; i <= n; i++)
        {
            cin >> a[i];
            c[i] = c[i - 1];
            if (a[i] < i)
                c[i]++;
            lol j = min(i - 1, a[i] - 1);
            if (j >= 0 && a[i] < i)
                ans += c[j];
        }
        cout << ans << endl;
    }

    return 0;
}