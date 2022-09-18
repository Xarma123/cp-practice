#include <bits/stdc++.h>
using namespace std;
const int N = 1e5;
vector<int> tree[N];
int Count[N], dp[N];
void dfs(int c,int p)
{
    Count[c]=1;
    for(auto e: tree[c])
    {   if(e!=p)
        {dfs(e,c);
        Count[c]+=Count[e];
        dp[c]+=Count[e]+dp[e];}
    }

}
void dfs1(int c,int p,vector<int> &ans)
{
    ans[c-1]=dp[c];
    for(auto e:tree[c])
    {
        if(e!=p)
        {
            dp[c]-=dp[e]+Count[e];
            Count[c]-=Count[e];
            dp[e]+=dp[c]+Count[c];
            Count[e]+=Count[c];
            dfs1(e,c,ans);
             dp[e]-=dp[c]+Count[c];
            Count[e]-=Count[c];
            dp[c]+=dp[e]+Count[e];
            Count[c]+=Count[e];

        }
    }
}
vector<int> distanceSum(int n, vector<vector<int>> edges)
{
    for (int i = 0; i < N; i++)
    {
        tree[i].clear();
        Count[i] = 0;
        dp[i] = 0;
    }
    for (auto e : edges)
    {
        tree[e[0]].push_back(e[1]);
        tree[e[1]].push_back(e[0]);
    }
    dfs(1,0);
    vector<int> ans(n, 0);
    dfs1(1,0,ans);

    return ans;
}
int main()
{
}