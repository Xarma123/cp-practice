#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n, q, ct;
    cin >> n >> q >> ct;
    lol s[ct + 1][101][101];

    for (lol k = 0; k <= ct; k++)
    {
        for (lol i = 0; i <= 100; i++)
        {
            for (lol j = 0; j <= 100; j++)
            {
                s[k][i][j] = 0;
            }
        }
    }
    vector<lol> w[101][101];
    while (n--)
    {
        lol x, y, si;
        cin >> x >> y >> si;
        s[0][x][y] += si;
        w[x][y].push_back(si);
    }

    for (lol k = 1; k <= ct; k++)
    {

        for (lol i = 1; i <= 100; i++)
        {
            for (lol j = 1; j <= 100; j++)
            {
                for (lol x = 0; x < w[i][j].size(); x++)
                {
                    w[i][j][x]++;
                    w[i][j][x] %= (ct + 1);
                    s[k][i][j] += w[i][j][x];
                }
            }
        }
    }

    for (lol k = 0; k <= ct; k++)
    {
        for (lol i = 0; i <= 100; i++)
        {
            for (lol j = 1; j <= 100; j++)
            {
                s[k][i][j] += s[k][i][j - 1];
            }
        }
        for (lol j = 0; j <= 100; j++)
        {
            for (lol i = 1; i <= 100; i++)
            {
                s[k][i][j] += s[k][i - 1][j];
            }
        }
    }

    while (q--)
    {
        lol t, x1, y1, x2, y2;
        cin >> t >> x1 >> y1 >> x2 >> y2;
        lol temp = s[(t % (ct + 1))][x2][y2] - s[(t % (ct + 1))][x2][y1 - 1] - s[(t % (ct + 1))][x1 - 1][y2] + s[(t % (ct + 1))][x1 - 1][y1 - 1];
        cout << temp << endl;
    }

    return 0;
}