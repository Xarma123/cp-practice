#include <bits/stdc++.h>
#define lol long long
using namespace std;
int solve(vector<string> &A)
{
    int dp[3][A[0].size()];
    bool dp1[3][A[0].size()];
    memset(dp1, false, sizeof(dp1));
    memset(dp, 0, sizeof(dp));
    for (int j = 0; j < A[0].size(); j++)
    {   
        int r = -1, g = -1, b = -1;
        for (int i = 0; i < A.size(); i++)
        { 
            if (A[i][j] == 'r')
            {
                dp1[0][j] = true;
                if (r == -1)
                    r = i;
            }
            if (A[i][j] == 'g')
            {
                dp1[1][j] = true;
                if (g == -1)
                    g = i;
            }
            if (A[i][j] == 'b')
            {
                dp1[2][j] = true;
                if (b == -1)
                    b = i;
            }
            if (A[i][j] == 'r')
            {
                if (g != -1)
                {
                    dp[2][j] = max(dp[2][j], i - g + 1);
                }
                if (b != -1)
                {
                    dp[1][j] = max(dp[1][j], i - b + 1);
                }
            }
            if (A[i][j] == 'g')
            {
                if (r != -1)
                {
                    dp[2][j] = max(dp[2][j], i - r + 1);
                }
                if (b != -1)
                {
                    dp[0][j] = max(dp[0][j], i - b + 1);
                }
            }

            if (A[i][j] == 'b')
            {
                if (r != -1)
                {
                    dp[1][j] = max(dp[1][j], i - r + 1);
                }
                if (g != -1)
                {
                    dp[0][j] = max(dp[0][j], i - g + 1);
                }
            }
         
        } 
       
    }
  

    int ans = 0;
    for (int j = 0; j < A[0].size(); j++)
    {
        for (int i = 0; i < 3; i++)
        {
            if (dp1[i][j])
            {
                for (int k = 0; k < A[0].size(); k++)
                {
                    ans = max(ans, (int)ceil(dp[i][k] * (abs(k - j) + 1) / 2.0));
                }
            }
        }
    }
    return ans;
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    vector<string> x = {"rrrrr", "rrrrg", "rrrrr", "bbbbb"};
    cout << solve(x);

    return 0;
}