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
        lol sum = 0;
        lol ans = LONG_LONG_MAX;
        for (lol i = 0; i < n; i++)
        {
            lol thick = i + 1; // i like em thick
            sum += a[i];
            lol csum = 0;
            bool val = true;
            lol l = i;
            for (lol j = i + 1; j < n; j++)
            {
                csum += a[j];
                if (csum > sum)
                {
                    val = false;
                    break;
                }
                if (csum == sum)
                {
                    csum = 0;
                    thick = max(thick, j - l);
                    l = j;
                }
            }
            if (csum == 0 && val)
            {
                ans = min(ans, thick);
            }
        }
        cout << ans << endl;
    }

    return 0;
}