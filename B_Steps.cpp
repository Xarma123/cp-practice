#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n, m;
    cin >> n >> m;
    lol xc, yc;
    cin >> xc >> yc;
    lol k;
    cin >> k;
    lol ans = 0;
    while (k--)
    {
        lol a, b;
        cin >> a >> b;
        lol ma;
        if (a == 0)
            ma = LONG_LONG_MAX;
        else if (a > 0)
        {
            ma = (n - xc) / a;
        }
        else
        {
            ma = (1-xc) / a;
        }
        lol mb;
        if (b == 0)
            mb = LONG_LONG_MAX;
        else if (b > 0)
        {
            mb = (m - yc) / b;
        }
        else
        {
            mb = (1-yc) / b;
        }
      
        lol se = min(ma, mb);
        ans += se;
        xc += a * 1ll * se;
        yc += b * 1ll * se;
    }
    cout << ans;

    return 0;
}