#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    lol w, h;
    while (cin >> w >> h)
    {
        if (w == 0 && h == 0)
            break;
        string a[h];
        for (lol i = 0; i < h; i++)
        {
            cin >> a[i];
        }
        lol d[h][w];
        set<pair<lol, pair<lol, lol>>> dij;
        for (lol i = 0; i < h; i++)
        {
            for (lol j = 0; j < w; j++)
            {
                d[i][j] = LONG_LONG_MAX;
                if (a[i][j] == 'S')
                {
                    dij.insert({0, {i, j}});
                }
            }
        }
        while (!dij.empty())
        {
            pair<lol, pair<lol, lol>> top = (*dij.begin());
            dij.erase(dij.begin());
            lol i = top.second.first;
            lol j = top.second.second;
            if (top.first >= d[i][j])
            {
                continue;
            }
            d[i][j] = top.first;
            lol dx[4] = {-1, 0, 0, 1};
            lol dy[4] = {0, -1, 1, 0};
            for (lol k = 0; k < 4; k++)
            {
                lol x = i + dx[k];
                lol y = j + dy[k];
                if (x >= 0 && x < h && y >= 0 && y < w)
                {
                    if (a[x][y] == 'D')
                    {
                        dij.insert({d[i][j], {x, y}});
                    }
                    else if (a[x][y] >= '1' && a[x][y] <= '9')
                    {
                        dij.insert({d[i][j] + (a[x][y] - '0'), {x, y}});
                    }
                }
            }
        }
        for (lol i = 0; i < h; i++)
        {
            for (lol j = 0; j < w; j++)
            {
                if (a[i][j] == 'D')
                {
                    cout << d[i][j] << endl;
                }
            }
        }
    }

    return 0;
}