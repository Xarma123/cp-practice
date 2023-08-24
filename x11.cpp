0,0,0,0,0,0,0
0,1,1,1,1,0,0
0,1,0,0,1,0,0
1,0,1,0,1,0,0
0,1,0,0,1,0,0
0,1,0,0,1,0,0
0,1,1,1,1,0,0
#include <bits/stdc++.h>
using namespace std;
#define lol long long
int n, m;
bool vis[201][201];
int dp[201][201];
vector<pair<int, int>> topo;
void dfs(int i, int j, vector<vector<int>> &matrix)
{
    if (vis[i][j])
        return;
    vis[i][j] = true;
    int dx[4] = {-1, 0, 0, 1};
    int dy[4] = {0, -1, 1, 0}; 
    cout<<i<<" "<<j<<endl;
    for (int k = 0; k < 4; k++)
    {
        int x = i + dx[k];
        int y = j + dy[k];
       
        if (x >= 0 && x < n && y >= 0 && y < m)
        {
             cout<<x<<" "<<y<<endl;
            if (matrix[x][y] > matrix[i][j])
            {    
                dfs(x, y, matrix);
                cout<<i<<" "<<j<<endl;
            }
        }
    }
    cout<<endl;
    topo.push_back({i, j});
}
void dfs1(int i, int j, vector<vector<int>> &matrix)
{
    if (vis[i][j])
        return;
    vis[i][j] = true;
    int dx[4] = {-1, 0, 0, 1};
    int dy[4] = {0, -1, 1, 0};
    dp[i][j] = 1;
    int ex = 0;
    for (int k = 0; k < 4; k++)
    {
        int x = i + dx[k];
        int y = j + dy[k];
        if (x >= 0 && x < n && y >= 0 && y < m)
        {
            if (matrix[x][y] > matrix[i][j])
            {
                dfs1(x, y, matrix);

                ex = max(ex, dp[x][y]);
            }
        }
    }

    dp[i][j] += ex;
}
int longestIncreasingPath(vector<vector<int>> &matrix)
{

     n = matrix.size();
     m = matrix[0].size();
    memset(vis, false, sizeof(vis));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!vis[i][j])
            {
                dfs(i, j, matrix);
            }
        }
    }
    memset(vis, false, sizeof(vis));
    memset(dp, 0, sizeof(dp));
    reverse(topo.begin(), topo.end());
    int ans = 0;
    for (auto e : topo)
    {
        dfs1(e.first, e.second, matrix);
        ans = max(ans, dp[e.first][e.second]);
    }
    if (n * m > 3)
        return dp[2][2];
    return -1;
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol a, b;
    cin >> a >> b;
    vector<vector<int>> v(a, vector<int>(b, 0));
    for (lol i = 0; i < a; i++)
    {
        for (lol j = 0; j < b; j++)
        {
            cin >> v[i][j];
        }
    }
    cout << longestIncreasingPath(v) << endl;
    for (auto e : topo)
    {
        cout << v[e.first][e.second] << endl;
    }
}