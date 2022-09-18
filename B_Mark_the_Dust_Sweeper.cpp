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
        lol a[n];
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        lol ans = 0;
        lol ex = 0, tot = 0;
        for (lol i = 0; i < n - 1; i++)
        {
            if (a[i] == 0 && tot == 0)
                continue;
            if (a[i] == 0)
            {
                if (ex > 0)
                {
                    ex--;
                    ans++;
                }
                else
                {
                    ans++;
                }
            }
            else
            {
                ex += a[i] - 1;
                tot += a[i];
            }
        }
        ans += tot;
        cout << ans << endl;
    }

    return 0;
}