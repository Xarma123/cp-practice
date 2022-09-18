// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    vector<lol> commonElements(lol A[], lol B[], lol C[], lol n1, lol n2, lol n3)
    {
        vector<lol> ans;
        lol i = 0, j = 0;
        while (i < n1 && j < n2)
        {
            if (A[i] == B[j])
            {
                ans.push_back(A[i]);
                j++;
                i++;
            }
            else
            {
                if (B[j] < A[i])
                {
                    while (B[j] < A[i])
                    {
                        j++;
                    }
                }
                else
                {
                    while (B[j] > A[i])
                    {
                        i++;
                    }
                }
            }
        }
        vector<lol> ans1;
        i = 0;
        j = 0;
        while (i < ans.size() && j < n3)
        {
            if (ans[i] == C[j])
            {
                ans1.push_back(ans[i]);
                j++;
                i++;
            }
            else
            {
                if (C[j] < ans[i])
                {
                    while (C[j] < ans[i])
                    {
                        j++;
                    }
                }
                else
                {
                    while (C[j] > ans[i])
                    {
                        i++;
                    }
                }
            }
        }  
        
        set<lol> x;
        for ( i = 0; i < ans1.size(); i++)
        {
            x.insert(ans1[i]);
        }
        ans1.clear();
        for (auto k = x.begin(); k!=x.end(); k++)
        {
           ans1.push_back((*k)) ;
        }
        
        return ans1;

    }
};

// { Driver Code Starts.

int main()
{
    lol t;
    cin >> t;
    while (t--)
    {
        lol n1, n2, n3;
        cin >> n1 >> n2 >> n3;
        lol A[n1];
        lol B[n2];
        lol C[n3];

        for (lol i = 0; i < n1; i++)
            cin >> A[i];
        for (lol i = 0; i < n2; i++)
            cin >> B[i];
        for (lol i = 0; i < n3; i++)
            cin >> C[i];

        Solution ob;

        vector<lol> res = ob.commonElements(A, B, C, n1, n2, n3);
        if (res.size() == 0)
            cout << -1;
        for (lol i = 0; i < res.size(); i++)
            cout << res[i] << " ";
        cout << endl;
    }
} // } Driver Code Ends