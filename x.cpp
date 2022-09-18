// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution{   
public:
    lol median(vector<vector<lol>> &matrix, lol r, lol c){ 
        
        // code here  
        lol s = 1;
        lol e = 2000;
        while (s < e )
        {
            lol m = (s + e) / 2;
            lol co = 0;
            for (lol i = 0; i < r; i++)
            {
                co += upper_bound(&matrix[i][0], &matrix[i][0] + c, m) - &matrix[i][0];
               
            } 
           
            if (co < (c * r) / 2 +1)
            {
                s = m;
            }
            else
                e = m;
        }
        return s;
        
        
        
    }
};

// { Driver Code Starts.

int main()
{
    lol t;
    cin>>t;
    while(t--)
    {
        lol r, c;
        cin>>r>>c;
        vector<vector<lol>> matrix(r, vector<lol>(c));
        for(lol i = 0; i < r; ++i)
            for(lol j = 0;j < c; ++j)
                cin>>matrix[i][j];
        Solution obj;
        cout<<obj.median(matrix, r, c)<<endl;        
    }
    return 0;
}  // } Driver Code Ends