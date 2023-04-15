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
        lol n, m;
        cin >> n >> m;
        lol x, y;
        cin >> x >> y;
        lol dx[4] = {-1, 0, 0, 1};
        lol dy[4] = {0, -1, 1, 0};
        lol a1 = 0, a2 = 0;
        for (lol k = 0; k < 4ll; k++)
        {
            if (x + dx[k] >= 1 && x + dx[k] <= n && y + dy[k] >= 1 && y + dy[k] <= m)
            {
                a1++;
            }
        }
        cin >> x >> y;
        for (lol k = 0; k < 4ll; k++)
        {
            if (x + dx[k] >= 1 && x + dx[k] <= n && y + dy[k] >= 1 && y + dy[k] <= m)
            {
                a2++;
            }
        }
        cout << min(a2, a1) << '\n';
    }

    return 0;
}