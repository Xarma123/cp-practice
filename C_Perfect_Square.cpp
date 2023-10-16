#include <bits/stdc++.h>
using namespace std;
#define lol long long
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
        string a[n];
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        lol ans = 0;
        for (lol st = 0; st < n / 2; st++)
        {
            lol x1 = st, y1 = st;
            lol x2 = st, y2 = n - st - 1;
            lol x3 = n - 1 - st, y3 = n - 1 - st;
            lol x4 = n - 1 - st, y4 = st;
            while (1)
            {
                char mx = max(a[x1][y1], max(a[x2][y2], max(a[x3][y3], a[x4][y4])));
                ans += mx - a[x1][y1];
                ans += mx - a[x2][y2];
                ans += mx - a[x3][y3];
                ans += mx - a[x4][y4];

                y1++;
                x2++;
                y3--;
                x4--;
                if (x4 == st)
                {
                    break;
                }
            }
        }
        cout << ans<<'\n';;
    }
}