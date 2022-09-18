// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function to return a list of lolegers denoting spiral traversal of matrix.
    vector<lol> spirallyTraverse(vector<vector<lol>> matrix, lol r, lol c)
    {
        lol rup = 0, rdn = r - 1, cr = c - 1, cl = 0;

        vector<lol> a;
        bool f = true;
        while (1)
        {
            f = true;
            if (rup < r)
            {
                for (lol i = cl; i <= cr; i++)
                {
                    a.push_back(matrix[rup][i]);
                    f = false;
                }
                rup++;
            }

            if (cr >= 0)
            {
                for (lol i = rup; i <= rdn; i++)
                {
                    a.push_back(matrix[i][cr]);
                    f = false;
                }
                cr--;
            }

            if (rdn >= 0)
            {
                for (lol i = cr; i >= cl; i--)
                {
                    a.push_back(matrix[rdn][i]);
                    f = false;
                }
                rdn--;
            }

            if (cl < c)
            {
                for (lol i = rdn; i >= rup; i--)
                {
                    a.push_back(matrix[i][cl]);
                    f = false;
                }
                cl++;
            } 
            
            if (f||a.size()==c*r)
                break;
           
        }

        return a;
    }
};

// { Driver Code Starts.
int main()
{
    lol t;
    cin >> t;

    while (t--)
    {
        lol r, c;
        cin >> r >> c;
        vector<vector<lol>> matrix(r);

        for (lol i = 0; i < r; i++)
        {
            matrix[i].assign(c, 0);
            for (lol j = 0; j < c; j++)
            {
                cin >> matrix[i][j];
            }
        }

        Solution ob;
        vector<lol> result = ob.spirallyTraverse(matrix, r, c);
        for (lol i = 0; i < result.size(); ++i)
            cout << result[i] << " ";
        cout << endl;
    }
    return 0;
} // } Driver Code Ends