#include <bits/stdc++.h>
#define lol long long
using namespace std;
lol lcs(string a, string b)
{
    stack<char> x;
    lol m = a.size(), n = b.size();
    lol ar[m + 1][n + 1];
    for (lol i = 0; i < m + 1; i++)
    {
        ar[i][0] = 0;
    }

    for (lol i = 0; i < n + 1; i++)
    {
        ar[0][i] = 0;
    }
    for (lol i = 1; i < m + 1; i++)
    {
        for (lol j = 1; j < n + 1; j++)
        {
            if (a[i - 1] == b[j - 1])
            {     cout<<a[i-1]<<" ";
                 
                ar[i][j] = 1 + ar[i - 1][j - 1];
            }
            else
            {
                ar[i][j] = max(ar[i - 1][j], ar[i][j - 1]);
            }
        } 
        
    } cout<<endl;
  
      while (!x.empty())
      {
         cout<< x.top();
         x.pop();
      }
      
    return ar[m][n];
}
int main()
{
    string a, b;
    cin >> a >> b;
    cout << lcs(a, b);
    return 0;
}