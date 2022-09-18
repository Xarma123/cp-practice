// { Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    bool check(string a)
    {
        lol i = 0;
        lol j = a.size() - 1;
        while (i < j)
        {
            if (a[i] != a[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
    lol palindromicPartition(string str)
    {
        // code here
        lol dp[str.size() + 1];
        dp[0] = -1;
        dp[1] = 0;
        for (lol i = 2; i <= str.size(); i++)
        {
            dp[i] = INT_MAX;
            for (lol j = i; j > 0; j--)
            {
                if (check(str.substr(j - 1, i - j + 1)))
                {
                    dp[i] = min(dp[i], dp[j - 1] + 1);
                }
            }
        }
        return dp[str.size()];
    }
};

// { Driver Code Starts.

int main()
{
    lol t;
    cin >> t;
    while (t--)
    {
        string str;
        cin >> str;

        Solution ob;
        cout << ob.palindromicPartition(str) << "\n";
    }
    return 0;
} // } Driver Code Ends