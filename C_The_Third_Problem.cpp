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
        lol m = 1e9 + 7;

        lol a[n];
        lol p[n];
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
            p[a[i]] = i;
        }

        lol l = p[0];
        lol r = p[0];
        lol i = 1;
        lol ans = 1;
        while (i < n)
        {
            if (!(p[i] >= l && p[i] <= r))
            {
                if (p[i] > r)
                {

                    r = p[i];
                }
                else
                {

                    l = p[i];
                }
            }
            else
            {
                ans = (ans * 1ll * (r - l + 1 - i)) % m;
            }

            i++;
        }
        cout << ans << endl;
    }

    return 0;
}