// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
#define lol long long
public:
    void merge(lol arr1[], lol arr2[], lol n, lol m)
    {

        lol i = 0;
        lol j = 0;
        while (i < n && j < m)
        {

            if (arr1[i] <= arr2[j])
            {
                i++;
            }
            else
            {
                swap(arr1[i], arr2[j]);
                i++;

                for (lol k = j + 1; k < m; k++)
                {
                    if (arr2[k] >= arr2[k - 1])
                    {
                        break;
                    }
                    else
                    {
                        swap(arr2[k], arr2[k - 1]);
                    }
                }
            }
        }
    }
};

// { Driver Code Starts.
int main()
{
    lol t;
    cin >> t;
    while (t--)
    {
        lol n, m, i;
        cin >> n >> m;
        lol arr1[n], arr2[m];
        for (i = 0; i < n; i++)
        {
            cin >> arr1[i];
        }
        for (i = 0; i < m; i++)
        {
            cin >> arr2[i];
        }
        Solution ob;
        ob.merge(arr1, arr2, n, m);
        for (i = 0; i < n; i++)
        {
            cout << arr1[i] << " ";
        }
        for (i = 0; i < m; i++)
        {
            cout << arr2[i] << " ";
        }
        cout << "\n";
    }
    return 0;
} // } Driver Code Ends