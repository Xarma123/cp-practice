#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol t;
    cin >> t;
    while (t--)
    {
        lol W, H;
        cin >> W >> H;
        lol x1, y1, x2, y2, w, h;
        cin >> x1 >> y1 >> x2 >> y2 >> w >> h;

        lol ans = INT_MAX;
        if (H < h || W < w)
            cout << -1;
        else
        {
            if (x1 + W - x2 >= w)
            {
                lol move = w - x1;
                ans = min(ans, max(move, 0ll));
                move = w - (W - x2);
                ans = min(ans, max(move, 0ll));
            }
            if (H - y2 + y1 >= h)
            {
                lol move = h - (H - y2);
                ans = min(ans, max(move, 0ll));
                move = h - (y1);
                ans = min(ans, max(move, 0ll));
            }
            if (ans == INT_MAX)
                cout << -1 << endl;
            else
                cout << ans << endl;
        }
    }

    return 0;
}