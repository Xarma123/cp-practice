// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution
{
public:
   vector<string> a;
   void add(string ans, char i, lol n)
   {
      if (n == 0)
      {
         a.push_back(ans);
         return;
      }
      if (i > '9')
      {
         return;
      }

      for (; i <= '9'; i++)
      {
         ans.push_back(i);
         add(ans, (char)(i + 1), n - 1);
         ans.erase(ans.size() - 1);
      }
   }
   vector<lol> increasingNumbers(lol N)
   {
      string ans = "";
      if (N == 1)
         add(ans, '0', N);
      else
         add(ans, '1', N);
      vector<lol> as;
      for (lol i = 0; i < a.size(); i++)
      {
         as.push_back(stoi(a[i]));
      }
      return as;
   }
};

// { Driver Code Starts.
int main()
{
   lol t;
   cin >> t;
   while (t--)
   {
      lol N;
      cin >> N;
      Solution ob;
      vector<lol> ans = ob.increasingNumbers(N);
      for (auto num : ans)
      {
         cout << num << " ";
      }
      cout << endl;
   }
   return 0;
} // } Driver Code Ends