#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    return 0;
}
class Solution
{
public:
    int mincostTickets(vector<int> &days, vector<int> &cost)
    {
        int dp[367];

        memset(dp, 0, sizeof(dp));
        int j = days.size() - 1;
        for (int i = 365; i >= 0; i--)
        {
            if (j >= 0)
            {
                if (days[j] == i)
                {
                    dp[i] = cost[0] + dp[i + 1];
                    if (i + 7 < 367)
                    {
                        dp[i] = min(dp[i], cost[1] + dp[i + 7]);
                    }
                    else
                        dp[i] = min(dp[i], cost[1]);
                    if (i + 30 < 367)
                    {
                        dp[i] = min(dp[i], cost[2] + dp[i + 30]);
                    }
                    else
                        dp[i] = min(dp[i], cost[2]);
                    j--;
                }
                else
                    dp[i] = dp[i + 1];
            }
            else
                dp[i] = dp[i + 1];
        }
        return dp[1];
    }
};