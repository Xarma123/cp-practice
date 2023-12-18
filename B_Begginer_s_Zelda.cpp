#include <bits/stdc++.h>
using namespace std;
#define lol long long
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol t;
    cin >> t;
    while (t--)
    {
        lol n;
        cin >> n;
        map<lol, lol> ind;
        for (lol i = 0; i < n - 1; i++)
        {
            lol a, b;
            cin >> a >> b;
            ind[a]++;
            ind[b]++;
        }
        lol ans = 0;
        for (lol i = 1; i <= n; i++)
        {
            if (ind[i] == 1)
                ans++;
        }
        ans = (ans / 2ll) + (ans % 2);
        cout << ans << '\n';
    }

    return 0;
}
