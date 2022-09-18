// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution {
public:
    vector<lol> factorial(lol N){
        // code here 
        vector<lol> ans;
        ans.push_back(1);
        lol i = 2; 
        lol cary=0;
        while(i<=N)
        {   
            lol q = i;
            lol j=0;
            while(q>0)
            {
            cary=0;
            for(;j<ans.size();j++)
            {
                lol t = ans[j]*(q%10)+cary;
               
               
                    ans[j]=t%10;
                    t=t/10; 
                    cary=t;
                    
               
                    
                    
                
            } 
            if(cary!=0)
            ans.push_back(cary); 
            
            q=q/10 ;
                j++;
            }
            
            
            i++;
            
        } 
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

// { Driver Code Starts.

int main() {
    lol t;
    cin >> t;
    while (t--) {
        lol N;
        cin >> N;
        Solution ob;
        vector<lol> result = ob.factorial(N);
        for (lol i = 0; i < result.size(); ++i){
            cout<< result[i];
        }
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends