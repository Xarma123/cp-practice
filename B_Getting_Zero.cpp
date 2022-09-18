#include <bits/stdc++.h>
#define lol long long
using namespace std;
lol mn(lol v)
{
    lol c = 0;
    while (v % 2 == 0)
    {
        v /= 2;
        c++;
    }
    lol ans = 15 - c;
    return ans;
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n;
    cin >> n;

    while (n--)
    {
        lol t;
        cin >> t;
        lol ans = LONG_LONG_MAX;
        if (t == 0)
            cout << 0 << " ";
        else
        {
            for (lol i = t; i < t + 17; i++)
            {

                ans = min(mn(i) + i - t, ans);
            }
            cout << ans << " ";
        }
    }

    return 0;
}