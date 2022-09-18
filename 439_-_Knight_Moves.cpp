#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s;
    while (cin >> s)
    {
        string s2;
        cin >> s2;
        vector<vector<lol>> vis(8, vector<lol>(8, -1));
        lol x = s[0] - 'a';
        lol y = s[1] - '1';
        vis[x][y] = 0;
        queue<pair<lol, lol>> q;
        q.push({x, y});
        while (!q.empty())
        {
            pair<lol, lol> t = q.front();
            q.pop();
            lol dx[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
            lol dy[8] = {-1, 1, -2, 2, 2, -2, -1, 1};
            for (lol i = 0; i < 8; i++)
            {
                if (t.first + dx[i] >= 0 && t.first + dx[i] < 8 && t.second + dy[i] >= 0 && t.second + dy[i] < 8 && vis[t.first + dx[i]][t.second + dy[i]] == -1)
                {
                    vis[t.first + dx[i]][t.second + dy[i]] = vis[t.first][t.second] + 1;
                    q.push({t.first + dx[i], t.second + dy[i]});
                }
            }
        }
        x = s2[0] - 'a';
        y = s2[1] - '1';
        cout << "To get from "<<s<<" to "<<s2<<" takes "<<vis[x][y]<<" knight moves." << endl;
    }

    return 0;
}