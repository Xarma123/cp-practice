#include <bits/stdc++.h>
#define lol long long
using namespace std;
lol dp[1001][1001];
string s;
string solve(lol i, lol j)
{
    string re = "";
    if (i > j)
        return re;
    if (i == j)
    {
        re.push_back(s[i]);
        return re;
    }
    if (i == j - 1)
    {
        if (s[i] == s[j])
        {
            re.push_back(s[i]);
            re.push_back(s[i]);
            return re;
        }
        else
        {
            re.push_back(s[i]);
            re.push_back(s[j]);
            re.push_back(s[i]);
            return re;
        }
    }

    if (s[i] == s[j])
    {

        if (dp[i][j] == dp[i + 1][j - 1])
        {
            re.push_back(s[i]);
            re = re + solve(i + 1, j - 1);
            re.push_back(s[i]);
            return re;
        }
    }

    if (dp[i][j] == dp[i + 1][j] + 1)
    {
        re.push_back(s[i]);
        re = re + solve(i + 1, j);
        re.push_back(s[i]);
        return re;
    }
    if (dp[i][j] == dp[i][j - 1] + 1)
    {
        re.push_back(s[j]);
        re = re + solve(i, j - 1);
        re.push_back(s[j]);
        return re;
    }
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while (cin >> s)
    {
        memset(dp, 0, sizeof(dp));
        for (lol gap = 0; gap < s.size(); gap++)
        {
            for (lol i = 0, j = gap; j < s.size(); i++, j++)
            {
                if (i == j - 1)
                {
                    if (s[i] != s[j])
                        dp[i][j] = 1;
                }
                else
                {
                    dp[i][j] = LONG_LONG_MAX;
                    if (s[i] == s[j])
                    {
                        dp[i][j] = dp[i + 1][j - 1];
                    }
                    dp[i][j] = min(dp[i][j], min(dp[i][j - 1], dp[i + 1][j]) + 1);
                }
            }
        }
        cout << dp[0][s.size() - 1] << " ";
        cout << solve(0, s.size() - 1) << endl;
    }

    return 0;
}