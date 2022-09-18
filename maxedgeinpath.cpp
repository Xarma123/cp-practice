#include <bits/stdc++.h>
#define lol long long
using namespace std;
int mx[100005][18];
int blift[100005][18];
int level[100005];
map<int, vector<pair<int, int>>> mp;
void dfs(int i, int p, int c, bool visit[], int l)
{
    level[i] = l;
    blift[i][0] = p;
    visit[i] = true;
    for (int j = 1; j < 18; j++)
    {
        if (blift[i][j - 1] != -1)
        {
            blift[i][j] = blift[blift[i][j - 1]][j - 1];
        }
        else
            break;
    }
    mx[i][0] = c;
    for (int j = 1; j < 18; j++)
    {

        if (blift[i][j - 1] != -1)
        {
            mx[i][j] = max(mx[i][j - 1], mx[blift[i][j - 1]][j - 1]);
        }
        else
            break;
    }
    for (auto j = 0; j < mp[i].size(); j++)
    {
        if (!visit[mp[i][j].first])
        {
            dfs(mp[i][j].first, i, mp[i][j].second, visit, l + 1);
        }
    }
}
vector<int> solve(vector<vector<int>> &A, vector<vector<int>> &B)
{
    int n = A.size();
    n++;
    mp.clear();
    memset(blift, -1, sizeof(blift));
    memset(mx, -1, sizeof(mx));
    memset(level, -1, sizeof(level));
    for (int i = 0; i < A.size(); i++)
    {
        mp[A[i][0]].push_back({A[i][1], A[i][2]});
        mp[A[i][1]].push_back({A[i][0], A[i][2]});
    }
    bool visit[n + 1];
    for (int i = 0; i <= n; i++)
        visit[i] = false;

    dfs(1, -1, -1, visit, 0);
    vector<int> ans;

    for (int q = 0; q < B.size(); q++)
    {
        int a = B[q][0];
        int b = B[q][1];
        int lca;
        if (a == b)
        {
            ans.push_back(0);
            continue;
        }
        if (level[a] < level[b])
          swap(a, b);
        while (1)
        {
            int j;
            for (j = 17; j >= 0; j--)
            {
                if (blift[a][j] == -1)
                    continue;
                else if (level[blift[a][j]] <= level[b])
                {
                    continue;
                }
                else
                    break;
            }
            if (j != -1)
                a = blift[a][j];
            else
                break;
        }
        if (level[a] != level[b])
            a = blift[a][0];
        if (a == b)
            lca = a;
        else
        {
            while (1)
            {
                int j;
                for (j = 17; j >= 0; j--)
                {

                    if (blift[a][j] == -1 || blift[b][j] == -1)
                        continue;
                    else if (blift[a][j] == blift[b][j])
                    {
                        continue;
                    }
                    else
                        break;
                }
                if (j < 0)
                    break;
                else
                {
                    a = blift[a][j];
                    b = blift[b][j];
                }
            }
            lca = blift[a][0];
        }
        a = B[q][0];
        b = B[q][1];
        int v = INT_MIN;
        while (1)
        {
            int j;
            for (j = 17; j >= 0; j--)
            {
                if (blift[a][j] == -1)
                    continue;
                else if (level[blift[a][j]] <= level[lca])
                    continue;
                else
                    break;
            }
            if (j < 0)
                break;
            else
            {
                v = max(v, mx[a][j]);
                a = blift[a][j];
            }
        }
        if (level[a] != level[lca])
        v = max(v, mx[a][0]);

        while (1)
        {
            int j;
            for (j = 17; j >= 0; j--)
            {
                if (blift[b][j] == -1)
                    continue;
                else if (level[blift[b][j]] <= level[lca])
                    continue;
                else
                    break;
            }
            if (j < 0)
                break;
            else
            {
                v = max(v, mx[b][j]);
                b = blift[b][j];
            }
        }
        if (level[b] != level[lca])
            v = max(v, mx[b][0]);

        ans.push_back(v);
        
    } 
  
    return ans;
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    vector<vector<int>> a, b;
    a.push_back({3, 1,5437});
    a.push_back({2, 1,32392});
    a.push_back({5, 4, 14605});
    a.push_back({9, 3, 3903});
    a.push_back({10, 2,154});
    a.push_back({7, 1,293});
    a.push_back({4, 3,12383});
    a.push_back({8, 2,17422});
    a.push_back({11, 8,18717});
    a.push_back({6, 4,19719});
    b.push_back({10, 2});

    vector<int> ans = solve(a, b); 
    
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";

    return 0;
}