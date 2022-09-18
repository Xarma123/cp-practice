#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol x, y, x1, y1;
    cin >> x >> y >> x1 >> y1;
    lol n;
    cin >> n;
    set<pair<lol, lol>> point;
    for (lol i = 0; i < n; i++)
    {
        lol r, a, b;
        cin >> r >> a >> b;
        for (lol j = a; j <= b; j++)
        {
            point.insert({r, j});
        }
    }
    map<pair<lol, lol>, lol> dis;
    queue<pair<lol, lol>> q;
    q.push({x, y});
    dis[{x, y}] = 0;
    lol dx[8] = {0, 0, -1, -1, -1, 1, 1, 1};
    lol dy[8] = {-1, 1, 0, -1, 1, 0, -1, 1};
    while (!q.empty())
    {
        pair<lol, lol> y = q.front();
        q.pop();
        for (int i = 0; i < 8; i++)
        {
            if (point.count({y.first + dx[i], y.second + dy[i]}) && !dis.count({y.first + dx[i], y.second + dy[i]}))
            {
                dis[{y.first + dx[i], y.second + dy[i]}] = dis[{y.first, y.second}] + 1;
                q.push({y.first + dx[i], y.second + dy[i]});
            }
        }
    }
    if (dis.count({x1, y1}))
        cout << dis[{x1, y1}];
    else
        cout << -1;

    return 0;
}