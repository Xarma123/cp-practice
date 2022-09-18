#include <bits/stdc++.h>
#define lol long long
using namespace std;
int n, m;
bool check(int x, int y)
{
    if (x < 0 || x >= n || y < 0 || y >= m)
        return false;
    return true;
}
int solve(int A, int B, vector<string> &C)
{

    n = C.size();
    m = C[0].size();

    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {-1, 1, 0, 0};
    map<int, vector<pair<int, int>>> mp;
    for (int x = 0; x < n; x++)
    {
        for (int y = 0; y < m; y++)
        {
            int i;
            if (C[x][y] == 'U')
                i = 2;
            else if (C[x][y] == 'D')
                i = 3;
            else if (C[x][y] == 'L')
                i = 0;
            else
                i = 1;
            for (int k = 0; k < 4; k++)
            {
                int X = x + dx[k];
                int Y = y + dy[k];
                if (check(X, Y))
                {
                    if (k == i)
                    {
                        mp[x * m + y + 1].push_back({m * X + Y + 1, 0});
                      
                    }
                    else
                    {
                        mp[x * m + y + 1].push_back({m * X + Y + 1, 1});
                      
                    }
                }
            }
        }
    } 
    for (lol i = 1; i <= m*n; i++)
    {   cout<<i<<endl;
        for(auto j:mp[i])
        {
            cout<<j.first<<" "<<j.second<<endl;
        }
    }
    

    int t = m * (n - 1) + m;

    int dist[m * n + 1];
    memset(dist, INT_MAX, sizeof(dist));
    dist[1] = 0;
    set<pair<int, int>> pq;
    pq.insert(make_pair(0, 1));
    while (!pq.empty())
    {
        pair<int, int> x = (*pq.begin());
        pq.erase(x);
        if (x.first > dist[x.second])
            continue;
        for (auto i : mp[x.second])
        {
            if (dist[i.first] > dist[x.second] + i.second)
            {  

                dist[i.first] = dist[x.second] + i.second;

                pq.insert({dist[i.first], i.first});
            }
        }
    }
    return dist[m * n];
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    vector<string> x;
    x.push_back("RRRRRRRRRR");
    cout<<solve(1,10,x);

    return 0;
}