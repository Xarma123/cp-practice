// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function to find largest rectangular area possible in a given histogram.
    long long getMaxArea(long long arr[], lol n)
    {
        // Your code here
        stack<long long> x;
        long long ans = LONG_LONG_MIN;
        for (long long i = 0; i < n; i++)
        {
            if (x.empty())
            {
                x.push(i);
            }
            else
            {
                while (arr[x.top()] >= arr[i])
                {
                    long long cur = 0;
                    long long c = x.top();
                    x.pop();
                    cur += arr[c] * (i - c);

                    if (x.empty())
                    {
                        cur += arr[c] * (c);
                        ans = max(ans, cur);
                        break;
                    }
                    else
                    {
                        cur += arr[c] * (c - x.top() - 1);
                    }

                    ans = max(ans, cur);
                }
                x.push(i);
            }
        }
        while (!x.empty())
        {
            long long cur = 0;
            long long c = x.top();
            x.pop();
            cur += arr[c] * (n - c);
            if (x.empty())
            {
                cur += arr[c] * (c);
                ans = max(ans, cur);
                break;
            }
            else
            {
                cur += arr[c] * (c - x.top() - 1);
            }
            ans = max(ans, cur);
        }
        return ans;
    }
};

// { Driver Code Starts.

int main()
{
    long long t;

    cin >> t;
    while (t--)
    {
        lol n;
        cin >> n;

        long long arr[n];
        for (lol i = 0; i < n; i++)
            cin >> arr[i];
        Solution ob;
        cout << ob.getMaxArea(arr, n) << endl;
    }
    return 0;
}
// } Driver Code Ends