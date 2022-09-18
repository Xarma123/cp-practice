#include <bits/stdc++.h>
#define lol long long
using namespace std;

int main()
{
    string a;
    cin >> a;
    lol ans = 1;
    lol i;
    lol dp[a.size() + 1];
    dp[0] = 1;
    dp[1] = 1;
    for (i = 0; i < a.size(); i++)
    {
        if (a[i] == 'm' || a[i] == 'w')
            break;

        if (i > 0)
        {
            if(a[i]==a[i-1]&&(a[i]=='n'||a[i]=='u'))
            dp[i+1]= (dp[i]+dp[i-1])%(1000000007);
            else
            dp[i+1]=dp[i];
        }
    }
    if (i == a.size())
        cout << dp[a.size()];
    else
        cout << 0;

    return 0;
}