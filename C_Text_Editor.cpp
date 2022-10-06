#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    lol n;
    cin >> n;
    lol a[n];
    for (lol i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    lol r1, c1, r2, c2;
    cin >> r1 >> c1 >> r2 >> c2;
    queue<pair<lol, pair<lol, lol>>> q;
    q.push({0, {r1, c1}});
    lol ans = -1;
    bool vis[101][100005];
    for (lol i = 0; i < 101; i++)
    {
        for (lol j = 0; j < 100005; j++)
        {
            vis[i][j] = false;
        }
    }

    vis[r1][c1] = true;
    lol dx[4] = {-1, 1, 0, 0};
    lol dy[4] = {0, 0, -1, 1};

    while (!q.empty())
    {
        pair<lol, pair<lol, lol>> s = q.front();
        pair<lol, lol> top = s.second;
        q.pop();

        if (top.first == r2 && top.second == c2)
        {
            ans = s.first;
            break;
        }

        for (lol i = 0; i < 4; i++)
        {
            pair<lol, lol> e;
            if (dx[i] + top.first > n || dx[i] + top.first <= 0)
                continue;
            e.first = dx[i] + top.first;
            e.second = min(dy[i] + top.second, a[e.first - 1] + 1);
            e.second = max(e.second, 1ll);

            if (!vis[e.first][e.second])
            {
                vis[e.first][e.second] = true;
                q.push({s.first + 1, e});
                if (e.first == r2 && e.second == c2)
                {
                    ans = s.first + 1;
                    break;
                }
            }
        }
        if (ans != -1)
            break;
    }
    cout << ans;

    return 0;
}