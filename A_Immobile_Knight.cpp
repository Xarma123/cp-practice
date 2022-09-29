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
        lol dx[8] = {-2, -2, -1, 1, -1, 1, 2, 2};
        lol dy[8] = {-1, 1, -2, -2, 2, 2, -1, 1};
        bool f = true;
        for (lol i = 1; i <= n; i++)
        {
            for (lol j = 1; j <= m; j++)
            {

                lol k;
                for (k = 0; k < 8; k++)
                {
                    if (i + dx[k] >= 1 && i + dx[k] <= n && j + dy[k] >= 1 && j + dy[k] <= m)
                        break;
                }
                if (k == 8)
                {
                    cout << i << " " << j << endl;
                    f = false;
                    break;
                }
            }
            if (!f)
                break;
        }
        if (f)
            cout << 1 << " " << 1 << endl;
    }

    return 0;
}