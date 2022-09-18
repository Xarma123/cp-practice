#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol h, w;
    cin >> h >> w;
    string mat[h];
    for (lol i = 0; i < h; i++)
    {
        cin >> mat[i];
    }
    bool vis[h][w];
    memset(vis, false, sizeof(vis));
    bool ans = true;
    lol x = 0, y = 0;
    while (1)
    {
        if (vis[x][y])
        {
            ans = false;
            break;
        }
        vis[x][y] = true;
        if (mat[x][y] == 'U')
        {
            if (x == 0)
            {
                break;
            }
            x--;
        }
        else if (mat[x][y] == 'D')
        {
            if (x == h - 1)
            {
                break;
            }
            else
                x++;
        }
        else if (mat[x][y] == 'L')
        {
            if (y == 0)
                break;
            y--;
        }
        else
        {
            if (y == w - 1)
                break;
            y++;
        }
    }
    if (ans)
    {
        cout << x + 1 << " " << y + 1;
    }
    else
        cout << -1;

    return 0;
}