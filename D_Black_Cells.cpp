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
        lol n, k;
        cin >> n >> k;
        lol l[n], r[n];
        for (lol i = 0; i < n; i++)
            cin >> l[i];
        for (lol i = 0; i < n; i++)
            cin >> r[i];
        lol ans = LONG_LONG_MAX;
        lol tot = 0;
        lol c = 0;
        for (lol i = 0; i < n; i++)
        {
            if (r[i] - l[i] + 1 >= 2)
            {
                tot += r[i] - l[i] + 1;
            }
            else
            {
                c++;
                if (tot >= k)
                {
                    ans = min(ans, (i + 1 - c) * 2ll + r[i]);
                }
                else if (tot + c >= k)
                {

                    ans = min(ans, (i + 1 - (c - (k - tot))) * 2ll + r[i]);
                }
                continue;
            }
            if (tot >= k)
            {
                lol rt = max(r[i] - (tot - k), l[i]);
                ans = min(ans, (i + 1 - c) * 2ll + rt);
            }
            else if (tot + c >= k)
            {

                ans = min(ans, (i + 1 - (c - (k - tot))) * 2ll + r[i]);
            }
        }
        if (ans == LONG_LONG_MAX)
            ans = -1;
        cout << ans << '\n';
    }

    return 0;
}