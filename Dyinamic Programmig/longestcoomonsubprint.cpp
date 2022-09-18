#include <bits/stdc++.h>
#define lol long long
using namespace std; 
void prlol(lol i, lol j, lol c, lol r, lol *dp, stack<char> x, string s1, string s2)
{ bool flag =true;
    while (i > 0 && j > 0)
    {
        if (s1[i - 1] == s2[j - 1])
        {
            x.push(s1[i - 1]);
            i--;
            j--;
        }
        else
        {
            if (*(dp + ((i - 1) * c + j)) > *(dp + ((i * c) + j - 1)))
            {
                i--;
            }
            else if (*(dp + ((i - 1) * c + j)) == *(dp + ((i * c) + j - 1)))
            {
                prlol(i - 1, j, c, r, dp, x, s1, s2); 
                prlol(i , j-1, c, r, dp, x, s1, s2);  
                flag=false;
                break; 

            }
            else
            {
                j--;
            }
        }
    }
    while (!x.empty()&&flag)
    {
        cout << x.top();
        x.pop();
    } 
    cout<<endl;
}
lol lcs(string s1, string s2)
{
    lol ns1 = s1.size();
    lol ns2 = s2.size();
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
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
            {
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            }
        }
    }
    stack<char> x;
    lol i = ns1, j = ns2;
    prlol(i,j,ns2,ns1,*dp,x,s1,s2);

    return dp[ns1][ns2];
}



int main()
{
    string a, b;
    cin >> a >> b;
    cout << lcs(a, b);
    return 0;
}