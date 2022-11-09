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
        lol dp[s.size()][s.size()];
        string s2 = s;
        reverse(s2.begin(), s2.end());
        for (lol i = 0; i < s.size(); i++)
        {
            for (lol j = 0; j < s.size(); j++)
            {
                if (i == 0 && j == 0)
                {
                    if (s[i] == s2[j])
                        dp[i][j] = 1;
                    else
                        dp[i][j] = 0;
                }
                else if (i == 0)
                {
                    if (s[i] == s2[j])
                        dp[i][j] = 1;
                    else
                        dp[i][j] = 0;
                    dp[i][j] = max(dp[i][j], dp[i][j - 1]);
                }
                else if (j == 0)
                {
                    if (s[i] == s2[j])
                        dp[i][j] = 1;
                    else
                        dp[i][j] = 0;
                    dp[i][j] = max(dp[i][j], dp[i - 1][j]);
                }
                else
                {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                    if (s[i] == s2[j])
                    {
                        dp[i][j] = max(dp[i][j], 1 + dp[i - 1][j - 1]);
                    }
                }
            }
        }
        lol ans = dp[s.size() - 1][s.size() - 1];
        ans = ans / 2 + (ans % 2);
        lol iup = s.size() - 1;
        lol idown = s.size() - 1;
        lol taken = 0;
        string q = "";
        while (ans--)
        {
            map<char, lol> mp;
            for (lol j = 0; j <= idown; j++)
            {
                mp[s2[j]] = j;
            }
            char c = '\n';
            lol last = -1;
            lol last2 = -1;
            for (lol j = iup; j >= 0; j--)
            {
                if (mp.count(s[j]))
                {
                    if (dp[j][mp[s[j]]] == dp[s.size() - 1][s.size() - 1] - taken)
                    {
                        if (c == '\n')
                            c = s[j], last = j, last2 = mp[s[j]];
                        else if (s[j] < c)
                            c = s[j], last = j, last2 = mp[s[j]];
                    }
                }
            }
           
            taken++;
            q.push_back(c);
            iup = last - 1;
            idown = last2 - 1;
        }

        string q2 = q;
        reverse(q2.begin(), q2.end());
        if (dp[s.size() - 1][s.size() - 1] % 2)
            q.pop_back();

        q = q + q2;
        cout << q << endl;
    }

    return 0;
}