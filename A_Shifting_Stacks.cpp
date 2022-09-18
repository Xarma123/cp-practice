// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
/*You are required to complete this method */

class Solution
{
public:
    bool isKPartitionPossible(int a[], int n, int k)
    {

        sort(a, a + n);
        int s = 0;
        vector<int> b;
        for (int i = 0; i < n; i++)
        {
            b.push_back(a[i]);
            s += a[i];
        }
        if (s % k != 0)
            return false;
        s /= k;

        vector<int> rem;
        while (b.size() > 0)
        {
            rem.clear();
            for (int i = 0; i < powl(2, b.size()); i++)
            {
                int sum = 0;
                vector<int> sub;
                for (int j = 0; j < b.size(); j++)
                {
                    if ((i & (1 << j)))
                    {
                        sub.push_back(b[j]);
                        sum += b[j];
                    }
                }
                if (sum == s)
                {
                    rem.clear();

                    for (int j = 0; j < sub.size(); j++)
                    {
                        rem.push_back(sub[j]);
                    }
                }
            }
            if (rem.size() == 0)
                return false;

            for (int i = 0; i < rem.size(); i++)
            {

                b.erase(lower_bound(b.begin(), b.end(), rem[i]));
            }
        }
        return true;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;

        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        int k;
        cin >> k;
        Solution obj;
        cout << obj.isKPartitionPossible(a, n, k) << endl;
    }
} // } Driver Code Ends