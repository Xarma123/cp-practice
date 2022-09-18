#include <bits/stdc++.h>
#define lol long long
using namespace std;
lol lcs(string s1)
{    string s2;
    lol ns1 = s1.size();
    lol ns2 = ns1; 
   
     for ( auto i = s1.rbegin(); i!=s1.rend(); i++)
     {
         s2.push_back(*i);
     }   
    
     
    lol dp[ns1 + 1][ns2 + 1];
    for (lol i = 0; i <= ns1; i++)
    {
        dp[i][0] = 0;
    }
    for (lol i = 0; i <= ns2; i++)
    {
        dp[0][i] = 0;
    }
    for (lol i = 1; i <= ns1; i++)
    {
        for (lol j = 1; j <= ns2; j++)
        {
            if (s1[i - 1] == s2[j - 1])
                dp[i][j] = dp[i - 1][j - 1] +1;
            else
            {
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            }
        }
    }  
     stack<lol> x; 
      lol i = ns1,j=ns2;
     while (i > 0 && j > 0)
    {
        if (s1[i - 1] == s2[j - 1])
        {
            x.push(i - 1);
            i--;
            j--;
        }
        else
        {
            if (dp[i][j]<dp[i-1][j])
            {
                i--;
            }
           
            else
            {
                j--;
            }
        } 
 
    }  
    // char a='\0' ; 
    // bool flag=true;
    // lol ans = ns1-dp[ns1][ns2]; 

     while (!x.empty())
     {
        cout<<s1[x.top()];
        x.pop();
     }
     
    // if(x.top()) 
    //  for (lol i = ns1-1; i >=0; i--)
    //  {  
    //          if(x.top()==i)
    //          {   if(a=='\0')
    //              {
    //                  a=s1[i];
    //                  x.pop();
    //              }
    //              else
    //              {
    //                  if(a==s1[x.top()])
    //                  {
    //                      continue;
    //                  }
    //                  else
    //                  {
    //                      flag=false;
    //                      break;
    //                  }
    //              }



    //          }
         
    //  }
     

    
    // if(flag)
    // {
    //     return ans;
    // }
    // else
    // {
    //     return -1;
    // }

   
return dp[ns1][ns2];

  
}
int main()
{
    string a;
 
    
    cin >> a ;
       cout<<lcs(a);
    return 0;
}