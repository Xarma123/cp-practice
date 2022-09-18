#include <bits/stdc++.h>
#define lol long long
using namespace std;

lol op(lol n)
{
    lol dp[n + 1];
    for (lol i = 0; i <= n; i++)
    {
        dp[i] = INT_MAX;
    }

    dp[0] = 1;
    dp[1] = 0;
    dp[2] = 1;
    dp[3] = 1;

    lol a = INT_MAX;
    lol b = INT_MAX;
    lol c = INT_MAX;
    for (lol i = 4; i <= n; i++)
    {
        a = INT_MAX;
        b = INT_MAX;
        c = INT_MAX;
        if (dp[i] == INT_MAX)
        {
            if (i % 3 == 0)
            {
                a = dp[i / 3] + 1;
            }
            if (i % 2 == 0)
            {

                b = dp[i / 2] + 1;
            }
            if (dp[i - 1] >= 0)
                c = dp[i - 1] + 1;

            dp[i] = min(a, min(b, c));
        }
    }
  
    stack<lol> x;
    for (lol i = n; i >= 1;)
    {
        x.push(i);
        a = INT_MAX;
        b = INT_MAX;
        c = INT_MAX;
        if (i % 3 == 0)
        {
            a = dp[i / 3] + 1;
        }
        if (i % 2 == 0)
        {

            b = dp[i / 2] + 1;
        }
     
            c = dp[i - 1] + 1; 
           

        if (a <= b && a <= c)
        {
            i = i / 3;
        }
        else if (b < a && b <= c)
        {
            i = i / 2;
        }
        else
            i = i - 1;
    }
       cout<<x.size()-1<<endl;
    while (!x.empty())
    {
        cout << x.top() << " ";
        x.pop();
    }
    return 0;
}

int main()
{
    lol n;
    cin >> n;

    op(n);
    return 0;
}