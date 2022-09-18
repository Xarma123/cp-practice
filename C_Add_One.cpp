#include <bits/stdc++.h>
#define lol long long
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    lol t;
    cin >> t;
    lol dp[200001];
    for (lol i = 0; i <= 200000; i++)
    {
        if (i - 10 >= 0)
        {
            dp[i] = (dp[i - 9] + dp[i - 10]) % (1000000007);
        }
        else if (i - 9 >= 0)
        {
            dp[i] = (dp[i - 9] + 1) % (1000000007);
        }
        else
            dp[i] = 2;
    }
    while (t--)
    {
        string n;
        cin >> n;
        lol m;
        cin >> m;

        lol f = 0;
        for (lol i = 0; i < n.size(); i++)
        {
            lol M = m - (10 - (n[i] - '0'));
            if (M < 0)
                f++;
            else
                f = (f + dp[M]) % (1000000007);
        }
        cout << f << endl;
    }

    return 0;
}